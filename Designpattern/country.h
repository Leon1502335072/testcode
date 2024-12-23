#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include <iostream>
#include <string>
#include "Mediator.h"
using namespace std;

class Country
{
public:
    Country() = default;
    Country(MediatorOrg *org) : m_org(org) {}
    void setMediator(MediatorOrg* org)
    {
        m_org = org;
    }
    virtual void declare(string msg, string name = "") = 0;
    virtual void recvMessege(string msg) = 0;
    virtual string getName() = 0;
    virtual ~Country() {}
protected:
    // 中介者组织
    MediatorOrg *m_org;
};

// 阿拉巴斯坦
class Alabasta : public Country
{
public:
    using Country::Country;
    void declare(string msg, string name = "")
    {
        cout << "阿拉巴斯坦开始发布公告: " << endl;
        m_org->declare(msg, this, name);
    }
    void recvMessege(string msg)
    {
        cout << "阿拉巴斯坦得到的消息: " << msg << endl;
    }
    string getName()
    {
        return "阿拉巴斯坦";
    }

};

// 德雷斯罗萨
class Dressrosa : public Country
{
public:
    using Country::Country;

    void declare(string msg, string country = string()) override
    {
        cout << "德雷斯罗萨开始发布公告: " << endl;
        m_org->declare(msg, this, country);
    }
    void recvMessege(string msg) override
    {
        cout << "德雷斯罗萨得到的消息: " << msg << endl;
    }
    string getName()
    {
        return "德雷斯罗萨";
    }
};

// 露露西亚王国
class Lulusia : public Country
{
public:
    using Country::Country;

    void declare(string msg, string country = string()) override
    {
        cout << "露露西亚王国发布公告: " << endl;
        m_org->declare(msg, this, country);
    }
    void recvMessege(string msg) override
    {
        cout << "露露西亚王国得到的消息: " << msg << endl;
    }
    string getName()
    {
        return "露露西亚王国";
    }
};

// 卡玛巴卡王国
class Kamabaka : public Country
{
public:
    using Country::Country;

    void declare(string msg, string country = string()) override
    {
        cout << "卡玛巴卡王国发布公告: " << endl;
        m_org->declare(msg, this, country);
    }
    void recvMessege(string msg) override
    {
        cout << "卡玛巴卡王国得到的消息: " << msg << endl;
    }
    string getName()
    {
        return "卡玛巴卡王国";
    }
};


#endif