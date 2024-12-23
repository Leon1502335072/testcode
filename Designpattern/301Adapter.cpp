#include <iostream>
#include <functional>

/*
 * 适配器模式是一种结构型设计模式，就是用于将已有接口转换为调用者所期望的另一种接口。
 * 适配器模式让特定的API接口可以适配多种场景。例如，现有一个名为"Reader()"的API接口
 * 只能解析txt格式的文件，给这个Reader()接口增加适配器以后，它可以同时支持xml、json、
 * csv等格式的文件。
 */

// 饮料
class Beverage
{
public:
    virtual void getBeverage() = 0;
};

class CoffeeMaker
{
public:
    CoffeeMaker() = default;
    void Brew()
    {
        std::cout << "Make coffee!" << std::endl;
    }
};

class JuiceMaker
{
public:
    JuiceMaker() = default;
    void Squeeze()
    {
        std::cout << "Make Juice!" << std::endl;
    }
};

class Adapter:public Beverage
{
private:
    std::function<void()> m_cb;

public:
    Adapter(CoffeeMaker* cptr)
    {
        m_cb = [cptr](){ cptr->Brew(); };
        
    }
    Adapter(JuiceMaker* jptr)
    {
        m_cb = [jptr](){ jptr->Squeeze(); };
        
    }

    void getBeverage() override { m_cb(); }
};

int main()
{
    CoffeeMaker *coffee = new CoffeeMaker;
    Beverage *beverc = new Adapter(coffee);
    beverc->getBeverage();

    JuiceMaker *juice = new JuiceMaker;
    Beverage *beverj = new Adapter(juice);
    beverj->getBeverage();

    delete coffee, beverc, juice, beverj;
    return 0;
}