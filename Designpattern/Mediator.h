#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Country;

class MediatorOrg
{
public:
    void addMember(Country *country);
    virtual void declare(string msg, Country *country, string name) = 0;
    virtual ~MediatorOrg() {}

protected:
    map<string, Country *> m_countryMap;
};


// 世界政府
class WorldGovt : public MediatorOrg
{
public:
    void declare(string msg, Country *country, string name) override;
};

// 革命军
class GeMingArmy : public MediatorOrg
{
public:
    void declare(string msg, Country *country, string name) override;
};

#endif