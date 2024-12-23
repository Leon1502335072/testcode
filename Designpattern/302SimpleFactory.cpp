#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>


/*
 * 简单工厂：
 * 将一类的公共属性和接口抽象出来定义为接口类，子类通过重写这些虚方法来实例化对象，工厂类通过传入的类型
 * 创建出对应类型的对象，实现了类单一性的原则
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

enum class Type : char { tiger, lion, elephant };

class Factory
{
public:
    Factory() {}
    AbstractSimle* create(Type type)
    {
        AbstractSimle *abptr = nullptr;
        switch (type)
        {
        case Type::lion:
            abptr = new LionSimle;
            return abptr;
        case Type::elephant:
            abptr = new ElephantSimle;
            return abptr;
        case Type::tiger:
            abptr = new TigerSimle;
            return abptr;   
        default:
            return abptr;  
        }
    }
    
};

int main()
{
    Factory *factory = new Factory;
    AbstractSimle *tiger_obj = factory->create(Type::tiger);
    if(tiger_obj == nullptr)
    {
        return 0;
    }
    tiger_obj->Tansform();
    tiger_obj->GetAbility();

    AbstractSimle *lion_obj = factory->create(Type::lion);
    if(lion_obj == nullptr)
    {
        return 0;
    }
    lion_obj->Tansform();
    lion_obj->GetAbility();

    AbstractSimle *elephant_obj = factory->create(Type::elephant);
    if(elephant_obj == nullptr)
    {
        return 0;
    }
    elephant_obj->Tansform();
    elephant_obj->GetAbility();

    AbstractSimle *ptr = factory->create((Type)3);
    if(ptr == nullptr)
    {
        std::cout << "传入的类型错误！" << std::endl;
        return 0;
    }

    delete factory;
    delete tiger_obj, lion_obj, elephant_obj;

    return 0;
}