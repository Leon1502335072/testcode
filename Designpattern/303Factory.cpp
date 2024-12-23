#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

/*
 * 工厂模式：简单工厂的升级
 * 在简单工厂中如果公共的接口类又派生出了新的子类那么势必要修改简单工厂中的代码，这样一来就违反了开闭原则。
 * 而在工厂模式下将工厂抽象出来为每一种恶魔果实的类派生出一个子类工厂来生产对象，进一步做到了工厂子类的功能
 * 单一以及工厂和生产对象之间的解耦
 * 
 */


class AbstractSimle
{
public:
    virtual void Tansform() = 0;
    virtual void GetAbility() = 0;
    virtual ~AbstractSimle() {}
};

class TigerSimle: public AbstractSimle
{
public:
    void Tansform() override
    {
        std::cout << "变成虎兽人！" << std::endl;
    }
    void GetAbility() override
    {
        std::cout << "获得老虎的能力" << std::endl;
    }
};

class LionSimle: public AbstractSimle
{
public:
    void Tansform() override
    {
        std::cout << "变成狮兽人！" << std::endl;
    }
    void GetAbility() override
    {
        std::cout << "获得狮子的能力" << std::endl;
    }
};

class ElephantSimle: public AbstractSimle
{
public:
    void Tansform() override
    {
        std::cout << "变成象兽人！" << std::endl;
    }
    void GetAbility() override
    {
        std::cout << "获得大象的能力" << std::endl;
    }
};



class AbstractFactory
{
public:
    virtual AbstractSimle *create() = 0;
    virtual ~AbstractFactory() {}
};

// 老虎恶魔果实工厂 继承抽象工厂 只生产老虎恶魔果实(单一原则)
class TigerFactory:public AbstractFactory
{
public:
    AbstractSimle *create()
    {
        return new TigerSimle;
    }
    ~TigerFactory() { std::cout << "~TigerFactory()" << std::endl; }
};
// 狮子恶魔果实工厂 继承抽象工厂 只生产狮子恶魔果实(单一原则)
class LionFactory:public AbstractFactory
{
public:
    AbstractSimle *create()
    {
        return new LionSimle;
    }
    ~LionFactory() { std::cout << "~LionFactory()" << std::endl; }
};

// 大象恶魔果实工厂 继承抽象工厂 只生产大象恶魔果实(单一原则)
class ElephantFactory:public AbstractFactory
{
public:
    AbstractSimle *create()
    {
        return new ElephantSimle;
    }
    ~ElephantFactory() { std::cout << "~ElephantFactory()" << std::endl; }
};


int main()
{
    //创建对应的工厂
    AbstractFactory *tigerF = new TigerFactory;
    // 对应的工厂生产对应的恶魔果实
    AbstractSimle *tigerS = tigerF->create();
    tigerS->Tansform();
    tigerS->GetAbility();

    delete tigerF;
    delete tigerS;
    return 0;
}