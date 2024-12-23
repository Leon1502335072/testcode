#include<iostream>
#include<string>
using namespace std;


// 桥接模式（结构型模式）

/*
 * 桥接模式是一种结构型设计模式，用于将抽象与实现分离，其实本质上就是类与类之间的依赖关系
 * 比如车和车的颜色，这里的车类就是实现，颜色就是抽象，我们将颜色抽象出来然后通过形参的方
 * 式传递给车类，这样就解耦了车与颜色之间的关系，修改抽象类颜色的实现细节并不会影响车类的
 * 功能，扩展颜色的范围也是不影响的，即单一和开闭都符合了，而且代码维护起来也是很方便的
 * 
 */


class IColor
{
public:
    virtual string Color() = 0;
};

class RedColor : public IColor
{
public:
    string Color()
    {
        return "of Red Color";
    }
};

class BlueColor : public IColor
{
public:
    string Color()
    {
        return "of Blue Color";
    }
};

class ICarModel
{
public:
    virtual string WhatIsMyType() = 0;
};

class Model_A : public ICarModel
{
private:
    IColor* _myColor;
public:
    Model_A(IColor *obj) :_myColor(obj) {}
    string WhatIsMyType()
    {
        return "I am a Model_A " + _myColor->Color();
    }
};

class Model_B : public ICarModel
{
private:
    IColor* _myColor;
public:
    Model_B(IColor *obj) :_myColor(obj) {}
    string WhatIsMyType()
    {
        return "I am a Model_B " + _myColor->Color();
    }
};

int main()
{
    IColor* red = new RedColor();
    IColor* blue = new BlueColor();

    ICarModel* modelA = new Model_A(red);
    ICarModel* modelB = new Model_B(blue);

    cout << "\n" << modelA->WhatIsMyType();
    cout << "\n" << modelB->WhatIsMyType() << "\n\n";

    delete red;
    delete blue;
    delete modelA;
    delete modelB;
    return 0;
}
