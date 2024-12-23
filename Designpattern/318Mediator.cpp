#include <iostream>
#include <string>
#include <map>
#include "Mediator.h"
#include "country.h"
using namespace std;

// 中介者模式 (行为型设计模式)
/*
 * 中介者模式是一种行为型设计模式。它通过一个中介者对象将多个对象之间的交互关系进行封装，
 * 使得对象之间的交互需要通过中介者对象来完成。该设计模式的结构很容易理解，以中介者为中心。
 * 
 * 中介者模式的设计思想侧重于在对象之间增加一个用来调度的中介。
 * 
 * 有了中介者模式，各个对象可以专注于各自的业务处理逻辑，而不需要关心通信的具体实现细节。
 * 
 * 对象类之间通过中介者类的方法进行交互而不是直接进行交互，使得对象与对象之间的交互解耦
 * 假设 A 是具体的类，B 是具体的中介类，A中保存B的指针，B中保存A的指针 二者是相互关联关系
 * 
 */

void MediatorOrg::addMember(Country *country)
{
    country->setMediator(this);
    m_countryMap.insert(make_pair(country->getName(), country));
}

void  WorldGovt::declare(string msg, Country *country, string name)
{
    if(m_countryMap.find(name) != m_countryMap.end())
    {
        string str = msg + "【来自: " + country->getName() + "】";
        m_countryMap[name]->recvMessege(str);
    }
}

void  GeMingArmy::declare(string msg, Country *country, string name)
{
    string str = msg + "【来自: " + country->getName() + "】";
    for(auto &item : m_countryMap)
    {
        if(item.second == country)
        {
            continue;
        }
        item.second->recvMessege(str);
    }
}


int main()
{
    // 世界政府中介者组织
    WorldGovt *world = new WorldGovt;
    
    // 具体国家 
    Alabasta *alaba = new Alabasta;
    Dressrosa *dress = new Dressrosa;

    // 加入世界政府中介者组织
    world->addMember(alaba);
    world->addMember(dress);

    // 国家发布公告
    alaba->declare("德雷斯罗萨倒卖军火, 搞得我国连年打仗, 必须给个说法!!!", dress->getName());
    dress->declare("天龙人都和我多弗朗明哥做生意, 你算老几, 呸!!!", alaba->getName());

    GeMingArmy *geming = new GeMingArmy;
    Lulusia* lulu = new Lulusia;
    Kamabaka* kama = new Kamabaka;

    geming->addMember(lulu);
    geming->addMember(kama);

    lulu->declare("我草, 我的国家被伊姆毁灭了!!!");

    delete world;
    delete geming;
    delete alaba;
    delete dress;
    delete lulu;
    delete kama;

    return 0;
}