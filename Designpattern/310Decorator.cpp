#include <iostream>
#include <string>
using namespace std;


// 装饰器模式--结构型设计模式
/*
 * 装饰器模式：装饰器模式是一种结构型设计模式， 它允许在不改变现有对象的情况下，动态地将功能添加到对象中。
 * 就像穿衣服一样一件接着一件的进行包装
 * 装饰器模式是通过创建具有新行为的对象来实现的，这些对象将原始对象进行了包装。
 * 装饰器模式遵循开放/关闭原则，允许开发者在不修改现有代码的情况下添加新的装饰器。
 * 
 * W 抽象组件类，提供统一的接口
 * ↓
 * A具体被包装的对象类 B是装饰器基类，B中有成员A，即B和A是聚合关系 A通过B的构造函数传进来
 *                    ↓
 * C是具体装饰器，具有某一项具体的功能   D也是具体装饰器，具有某一项具体的功能
 * A和C、D也是聚合关系，然后C D将本类具体的功能装饰给A，且符合单一、开闭原则
 */



// Component 抽象组件(Component)：被装饰的对象，声明了对外的统一接口。具体对象和装饰器都要继承这个类
class IceCream {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

// 具体被装饰的对象类
class VanillaIceCream : public IceCream {
public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }

    double cost() const override { return 160.0; }
};

// 装饰器基类
class Decorator : public IceCream {
protected:
    IceCream* iceCream;

public:
    Decorator(IceCream* ic)
             :iceCream(ic){}
    
    

    string getDescription() const override
    {
        return iceCream->getDescription();
    }

    double cost() const override
    {
        return iceCream->cost();
    }
};

// Concrete Decorator - adds chocolate topping.
class ChocolateDecorator : public Decorator 
{
public:
    ChocolateDecorator(IceCream* ic)
                    : Decorator(ic){}
    
    // 添加新的功能--添加巧克力
    string getDescription() const override
    {
        return iceCream->getDescription()
            + " with Chocolate";
    }

    double cost() const override
    {
        return iceCream->cost() + 100.0;
    }
};

// Concrete Decorator - adds caramel topping.
class CaramelDecorator : public Decorator {
public:
    CaramelDecorator(IceCream* ic)
        : Decorator(ic){}
    
    // 添加焦糖
    string getDescription() const override
    {
        return iceCream->getDescription() + " with Caramel";
    }

    double cost() const override
    {
        return iceCream->cost() + 150.0;
    }
};

int main()
{
    // Create a vanilla ice cream
    IceCream* vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription()
        << ", Cost: Rs." << vanillaIceCream->cost()
        << endl;

    // Wrap it with ChocolateDecorator
    IceCream* chocolateIceCream = new ChocolateDecorator(vanillaIceCream);       
    cout << "Order: " << chocolateIceCream->getDescription()
        << ", Cost: Rs." << chocolateIceCream->cost()
        << endl;

    // Wrap it with CaramelDecorator
    IceCream* caramelIceCream = new CaramelDecorator(chocolateIceCream);      
    cout << "Order: " << caramelIceCream->getDescription()
        << ", Cost: Rs." << caramelIceCream->cost()
        << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete caramelIceCream;

    return 0;
}