#include <iostream>
#include <string>
using namespace std;

class Soldier
{
public:
    Soldier() {}
    Soldier(string name):m_name(name) {}
    string getName()
    {
        return m_name;
    }
    virtual void fight() = 0;
    virtual ~Soldier() {}
protected:
    string m_name = string();
};

class Teach : public Soldier
{
public:
    using Soldier::Soldier;
    void fight() override
    {
        cout << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

class DevilFruit : public Soldier
{
public:
    void enchantment(Soldier* soldier)
    {
        m_soldier = soldier;
        // m_soldier->m_name 由于m_name是protected的，子类可见对象不可见所以编译不通过
        m_name = soldier->getName();
    }

protected:
    // 装饰的对象
    Soldier *m_soldier = nullptr;
};

class DarkFruit : public DevilFruit
{
public:
    void fight() override
    {
        // 原来的技能
        m_soldier->fight();
        cout << m_soldier->getName() << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << endl;
    }
};

class QuakeFruit : public DevilFruit
{
public:
    void fight() override
    {
        // 原来的技能
        m_soldier->fight();
        cout << m_soldier->getName() << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << endl;
    }
};

class PieFruit : public DevilFruit
{
public:
    void fight() override
    {
        // 原来的技能
        m_soldier->fight();
        cout << m_soldier->getName() << "吃了大丙果实, 加护甲...!" << endl;
    }
};

int main()
{
    Soldier *soldier = new Teach;
    DevilFruit *dark = new DarkFruit;
    DevilFruit *quake = new QuakeFruit;
    DevilFruit *pie = new PieFruit;

    //soldier->fight();
    dark->enchantment(soldier);
    
    quake->enchantment(dark);
   
    pie->enchantment(quake);
    pie->fight();

    delete soldier, dark, quake, pie;

    return 0;
}