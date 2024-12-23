#include <iostream>
using namespace std;


// 责任链模式（行为型设计模式）
/*
 * 责任链模式：它让多个对象依次处理收到的请求，直到处理完成为止
 * 职责链模式需要使用多个对象，其中的每个对象要么处理请求，要么将请求传递给下一个对象，该模式因此可以实现发送方与接收方的松散耦合。
 * 在职责链模式中，一个对象可以被理解为处理器，每个处理器都包含对下一个处理器的引用，多个对象之间形成了一个链表的结构
 * 审批流程：在流程中，当一个申请需要多级审批时，可以使用职责链模式。每一级审批者都是职责链的一部分。
 * 
 * W 抽象基类 定义了一个统一处理请求的接口handle 以及一个自身成员变量 W* manager
 * ↓
 * A B C 都是W的派生类，根据自身等级和职责的不同来实现各自的handle 以及设置自己的上级也就是给manager赋值
 * 假如A B C的等级是依次递减的，那么C中的manager=B，B中的manager=A 所以他们之间是聚合关系
 * 当C的等级不够时就调B的handle来处理，B的等级也不够时就调A的handle来处理，就这样一级一级往
 * 上转，直到找到可以处理该请求的类
 */

enum class TypeRequest : char { Qingjia, Zhangxin, Cizhi };

class AbstractManager
{
public:
    AbstractManager():manager(nullptr) {}
    void setMyManager(AbstractManager *manager)
    {
        this->manager = manager;
    }
    virtual void handleRequest(TypeRequest type) = 0;
    virtual ~AbstractManager() {}
protected:
    AbstractManager *manager;
};

class Manager:public AbstractManager
{
public:
    void handleRequest(TypeRequest type)
    {
        switch (type)
        {
        case TypeRequest::Qingjia:
            cout << "我是manager，同意请假，好好休息~~~" << endl;
            break;
        case TypeRequest::Zhangxin:
            cout << "我是manager涨薪这个我得请示一下咱们CEO..." << " ====> ";
            manager->handleRequest(type);
            break;
        case TypeRequest::Cizhi:
            cout << "我是manager辞职这个我给你向上级反应一下..." << " ====> ";
            manager->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

class CEO : public AbstractManager
{
public:
    void handleRequest(TypeRequest type)
    {
        switch (type)
        {
        case TypeRequest::Qingjia:
            cout << "我是ceo，同意请假，好好休息~~~" << endl;
            break;
        case TypeRequest::Zhangxin:
            cout << "我是ceo，你工资不少了, 给你个购物券吧..." << endl;
            break;
        case TypeRequest::Cizhi:
            cout << "我是ceo，辞职我给你向上级反应一下..." << " ====> ";
            manager->handleRequest(type);
            break;
        default:
            break;
        }
    }
};

class BOSS : public AbstractManager
{
public:
    void handleRequest(TypeRequest type)
    {
        switch (type)
        {
        case TypeRequest::Qingjia:
            cout << "我是boss，同意请假，好好休息~~~" << endl;
            break;
        case TypeRequest::Zhangxin:
            cout << "我是boss，你工资不少了, 给你个购物券吧..." << endl;
            break;
        case TypeRequest::Cizhi:
            cout << "我是ceo，巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << endl;
            break;
        default:
            break;
        }
    }
};

class DACONGMING
{
public:
    void request(TypeRequest type, AbstractManager* manager)
    {
        manager->handleRequest(type);
    }
};

int main()
{
    Manager *manager = new Manager;
    CEO *ceo = new CEO;
    BOSS *boss = new BOSS;

    manager->setMyManager(ceo);
    ceo->setMyManager(boss);

    DACONGMING *boy = new DACONGMING;
    
    // 直接将请求给直接领导
    boy->request(TypeRequest::Cizhi, manager);
    boy->request(TypeRequest::Zhangxin, manager);
    boy->request(TypeRequest::Qingjia, manager);
    cout << "==========================================" << endl;
    // 直接将请求给ceo
    boy->request(TypeRequest::Cizhi, ceo);
    boy->request(TypeRequest::Zhangxin, ceo);
    boy->request(TypeRequest::Qingjia, ceo);
    cout << "==========================================" << endl;
    // 直接将请求给boss
    boy->request(TypeRequest::Cizhi, ceo);
    boy->request(TypeRequest::Zhangxin, ceo);
    boy->request(TypeRequest::Qingjia, ceo);

    delete manager;
    delete ceo;
    delete boss;
    delete boy;
    return 0;
}