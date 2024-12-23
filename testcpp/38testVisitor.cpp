#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

// 访问者模式（行为型设计模式）
/*
 * 访问者模式：将具体元素对象类和操作解耦
 * 同一种元素可以被不同的访问者访问，同一个访问者也可以访问不同的元素，这就是元素对象和操作的解耦
 * 
 * 具体元素类提供一个统一的Accep接口传入访问者对象（形参），传入的访问者类型的不同，那么该访问者对该
 * 元素的实际具体操作也会不同。从访问者来看，访问者基类抽象出了所有元素的访问接口，在派生的子访问者中
 * 就需要根据自身的特点来重写基类中的每一个虚接口，每一个虚接口都传入一个与该接口类型对应的元素类型的
 * 对象，即访问者和元素之间是相互依赖的关系
 * 
 */

class Visitor;

// 药品抽象基类
class AbstractMedicine
{
public:
    virtual void Accept(Visitor *visitor) = 0;
    virtual string getName() = 0;
    virtual int getPrice() = 0;
    virtual ~AbstractMedicine() {}
};

class AsplMedicine: public AbstractMedicine
{
public:
    void Accept(Visitor *visitor) override;
    string getName() override
    {
        return "阿司匹林";
    }
    int getPrice() override
    {
        return 10;
    }
};

class FftdnhspMedicine: public AbstractMedicine
{
public:
    void Accept(Visitor *visitor) override;
    string getName() override
    {
        return "氟伐他汀钠缓释片";
    }
    int getPrice() override
    {
        return 12;
    }
};


class DlxMedicine: public AbstractMedicine
{
public:
    void Accept(Visitor *visitor) override;
    string getName() override
    {
        return "黛力新";
    }
    int getPrice() override
    {
        return 12;
    }
};

// 访问者基类
class Visitor
{
public:
    virtual void visitorForAspl(AsplMedicine *aspl) = 0;
    virtual void visitorForFftdnhsp(FftdnhspMedicine *ff) = 0;
    virtual void visitorForDlx(DlxMedicine *dlx) = 0;
    virtual ~Visitor() {}
};

// 医生
class Doctor_Visitor: public Visitor
{
public:
    void visitorForAspl(AsplMedicine *aspl) override
    {
        cout << "医生：“"<<aspl->getName()<<"一日三次，一次一片！”" << endl;
    }
    void visitorForFftdnhsp(FftdnhspMedicine *ff) override
    {
        cout << "医生：“"<<ff->getName()<<"一日一次，一次两片！”" << endl;
    }
    void visitorForDlx(DlxMedicine *dlx) override
    {
        cout << "医生：“"<<dlx->getName()<<"一日两次次，一次一片！”" << endl;
    }
};

// 收费人员
class SFRY_Visitor: public Visitor
{
public:
    void visitorForAspl(AsplMedicine *aspl) override
    {
        cout << aspl->getName()<< "的价格是："<< aspl->getPrice() << endl;
        totalPrice += aspl->getPrice();
    }
    void visitorForFftdnhsp(FftdnhspMedicine *ff) override
    {
        cout << ff->getName()<< "的价格是："<< ff->getPrice() << endl;
        totalPrice += ff->getPrice();
    }
    void visitorForDlx(DlxMedicine *dlx) override
    {
        cout << dlx->getName()<< "的价格是："<< dlx->getPrice() << endl;
        totalPrice += dlx->getPrice();        
    }

    void getTotalprice() 
    {
        cout << "统计所有药品的价格是：" << totalPrice << endl;
    }

private:
    int totalPrice = 0;
};

// 取药人员
class QYRY_Visitor: public Visitor
{
public:
    void visitorForAspl(AsplMedicine *aspl) override
    {
        cout << "已经取到药品：" << aspl->getName() << endl;
    }
    void visitorForFftdnhsp(FftdnhspMedicine *ff) override
    {
        cout << "已经取到药品：" << ff->getName() << endl;
    }
    void visitorForDlx(DlxMedicine *dlx) override
    {
        cout << "已经取到药品：" << dlx->getName() << endl;
    }

};

// 药品管理者
class MedinceManager
{
public:
    void addMedince(AbstractMedicine* medince)
    {
        m_medinceList.push_back(medince);
    }

    void proAction(Visitor* visitor)
    {
        for(auto& medince:m_medinceList)
        {
            medince->Accept(visitor);
        }
    }

private:
    list<AbstractMedicine *> m_medinceList;
};

void AsplMedicine::Accept(Visitor *visitor)
{
    visitor->visitorForAspl(this);
}
void FftdnhspMedicine::Accept(Visitor *visitor)
{
    visitor->visitorForFftdnhsp(this);
}

void DlxMedicine::Accept(Visitor *visitor)
{
    visitor->visitorForDlx(this);
}

int main()
{
    Doctor_Visitor *doctor = new Doctor_Visitor;
    SFRY_Visitor   *sfry   = new SFRY_Visitor;
    QYRY_Visitor   *qyry   = new QYRY_Visitor;

    MedinceManager *medinceMgr = new MedinceManager;
    medinceMgr->addMedince(new AsplMedicine);
    medinceMgr->addMedince(new FftdnhspMedicine);
    medinceMgr->addMedince(new DlxMedicine);

    medinceMgr->proAction(doctor);
    cout << "======================================" << endl;
    medinceMgr->proAction(sfry);
    sfry->getTotalprice();
    cout << "======================================" << endl;
    medinceMgr->proAction(qyry);

    delete doctor;
    delete sfry;
    delete qyry;
    delete medinceMgr;

    return 0;
}