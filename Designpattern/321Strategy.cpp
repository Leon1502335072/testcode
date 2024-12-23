#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 策略模式（行为型设计模式）


/*
 * 策略模式将不同的算法实现封装成独立的类，使得算法的修改不会影响到客户端代码，提高了
 * 应用程序的灵活性和可维护性。策略模式的架构可以避免使用大量的if-else条件语句来大量
 * 判段不同的策略分支，优化了代码结构，增加了代码的可扩展性。
 * 
 * 有一个抽象策略类，B C D都是具体策略类
 * 策略模式有一个策略上下文的类 A ，A 中保存了抽象策略类的指针，通过传入的具体策略对象给其
 * 赋值，然后在 A 的内部调某种具体策略的具体方法来实现某些功能，这使得策略和策略调用者之间
 * 进行了解耦，调用者也就是A不需要关注 B C D 中的具体实现，只管调用即可，B C D 中细节的实
 * 现反过来又不影响调用者A的封装，符合某种情况下的单一、开闭原则。
 * 
 */


class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

class YiDang:public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是一档: ";
        if(isfar)
        {
            cout << "橡胶机关枪" << endl;
        }
        else
        {
            cout << "橡胶·攻城炮" << endl;
        }
    }
};


// 2档
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是2档: ";
        if (isfar)
        {
            cout << "橡胶Jet火箭" << endl;
        }
        else
        {
            cout << "橡胶Jet·铳乱打" << endl;
        }
    }
};

// 3档
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是3档: ";
        if (isfar)
        {
            cout << "橡胶巨人回旋弹" << endl;
        }
        else
        {
            cout << "橡胶巨人战斧" << endl;
        }
    }
};

// 4档
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是4档: ";
        if (isfar)
        {
            cout << "橡胶狮子火箭炮" << endl;
        }
        else
        {
            cout << "橡胶犀牛榴弹炮" << endl;
        }
    }
};

// 5档
class WuDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成五挡: 变成尼卡形态可以把物体变成橡胶, 并任意改变物体的形态对其进行攻击!!!" << endl;
    }
};

enum class Level : char
{
    easy,
    normal,
    hard,
    experts,
    professional
};

class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if(strategy != nullptr)
        {
            delete strategy;
            strategy = nullptr;
        }
        switch (level)
        {
        case Level::easy:
            strategy = new YiDang;
            break;
        case Level::normal:
            strategy = new ErDang;
            break;
        case Level::hard:
            strategy = new SanDang;
            break;
        case Level::experts:
            strategy = new SiDang;
            break;
        case Level::professional:
            strategy = new WuDang;
            break;
        default:
            break;
        }
        strategy->fight(isfar);
    }
    ~Luffy()
    {
        if(strategy)
        {
            delete strategy;
            strategy = nullptr;
        }
    }

private:
    AbstractStrategy *strategy = nullptr;
};

int main()
{
    Luffy* luffy = new Luffy;
    cout << "--- 在香波地群岛遇到了海军士兵: " << endl;
    luffy->fight(Level::easy);
    cout << "--- 在魔谷镇遇到了贝拉米: " << endl;
    luffy->fight(Level::normal);
    cout << "--- 在司法岛遇到了罗布·路奇: " << endl;
    luffy->fight(Level::hard);
    cout << "--- 在德雷斯罗萨遇到了多弗朗明哥: " << endl;
    luffy->fight(Level::experts);
    cout << "--- 在鬼岛遇到了凯多: " << endl;
    luffy->fight(Level::professional);
    delete luffy;
    return 0;

    return 0;
}