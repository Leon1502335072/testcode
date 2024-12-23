#include <iostream>
#include "State.h"
#include "Sanji.h"
#include <vector>
using namespace std;


// 状态模式（行为型设计模式）
/*
 * 状态模式允许对象在内部状态发生切换时改变它自身的行为
 * 
 * 状态模式的主要目的是将复杂的状态切换逻辑抽象化为一组离散的状态类，使代码结构更加清晰和易于维护
 * 
 * W 抽象状态基类 B C D 为具体状态类
 * A 是状态上下文类也就是说状态 B C D 可以作用于A，在该种状态下A可以表现出特定的行为 A中有成员保
 * 用来存传入的状态。A中提供一个设置状态的接口。在具体状态 B C D 中A作为形参传入 可以根据A提供的
 * 接口来切换状态，从A的视角来看他们是聚合或者组合的关系，从B C D角度来看他们是依赖关系
 * 
 */


void ForenoonState::working(SanJi* sanji)
{
    // 得到当前的time
    int time = sanji->getClock();
    // 判断时间点
    if (time < 8)
    {
        cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..." << endl;
    }
    else if (time > 8 && time < 11)
    {
        cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << endl;
    }
    else
    {
        // 切换到另一个状态
        sanji->setState(new NoonState);
        sanji->working(); // 山治的working是调状态的working
    }
}

void NoonState::working(SanJi* sanji)
{
    // 得到当前的time
    int time = sanji->getClock();
    // 判断时间点
    if (time < 13)
    {
        cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..." << endl;
    }
    else
    {
        // 切换到另一个状态
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(SanJi* sanji)
{
    // 得到当前的time
    int time = sanji->getClock();
    // 判断时间点
    if (time < 15)
    {
        cout << "当前时间<" << time << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << endl;
    }
    else if (time > 15 && time < 18)
    {
        cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..." << endl;
    }
    else
    {
        // 切换到另一个状态
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(SanJi* sanji)
{
    // 得到当前的time
    int time = sanji->getClock();
    // 判断时间点
    if (time < 19)
    {
        cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..." << endl;
    }
    else
    {
        cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..." << endl;
    }
}

#if 1
int main()
{
    SanJi* sanji = new SanJi;
    // vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
    // for (auto item : data)
    // {
    //     sanji->setClock(item);
    //     sanji->working();
    // }

    sanji->setClock(12);
    sanji->working();
    delete sanji;
    return 0;
}
#endif