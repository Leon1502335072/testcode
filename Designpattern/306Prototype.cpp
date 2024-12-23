#include <iostream>

// 原型模式 其实就是多态的应用

class GermaSoldier
{
public:
    virtual GermaSoldier *clone() = 0;
    virtual void whoAmI() = 0;
    virtual ~GermaSoldier() {}
};
class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier *clone() override
    {
        return new Soldier66(*this);
    }
    void whoAmI() override
    {
        std::cout << "我是Soldier66类型士兵" << std::endl;
    }
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier *clone() override
    {
        return new Soldier67(*this);
    }
    void whoAmI() override
    {
        std::cout << "我是Soldier67类型士兵" << std::endl;
    }
};

int main()
{
    GermaSoldier* obj = new Soldier66;
    GermaSoldier *soldier = obj->clone();
    soldier->whoAmI();
    // 执行delete操作后系统会将该指针指向的堆空间的内存释放 但此时的obj和soldier是创建在栈的指针变量 此时这两个变量还有值还指向
    // 那块堆上面的空间内存，此时在操作这个指针就是不安全的了也就是所谓的野指针，这就是一般说的delete后指针要置空
    delete obj;
    delete soldier;
    std::cout << "after delete: " << obj << "  " << soldier << std::endl;
    obj = nullptr;
    soldier = nullptr;

    GermaSoldier *p = new Soldier66;
    GermaSoldier *p2 = new Soldier66;

    obj = new Soldier67;
    soldier = obj->clone();
    soldier->whoAmI();
    delete obj;
    delete soldier;
    
    std::cout<< "after delete: "<< obj << "  " << soldier << std::endl;

    return 0;
}