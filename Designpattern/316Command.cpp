#include <iostream>
#include <list>
#include <map>
using namespace std;

// 命令模式（行为型设计模式）
/*
 * 命令模式：
 * 
 * 
 * 1、命令接口：AbstractCommand定义了一个execute方法，所有具体命令都需要实现这个方法。
 * 2、接收者：CookerZeff类有四个方法makeDSX、makeYXRS、makeHSPG、makeGBJD用来控制做什么菜
 * 3、具体命令：DSXcommand...类实现了AbstractCommand接口，并持有一个CookerZeff对象的指针，
 *    以便在执行时调用相应的方法。
 * 4、调用者：WaiterLuffy类持有一组命令对象，并在notify方法中调用这些命令的 execute 方法。
 * 5、客户端：在 main 函数中，创建了厨师对象和命令对象，并通过 WaiterLuffy 来执行命令。
 * 
 * 这种模式的优点是可以将请求的发送者和接收者解耦，支持命令的撤销和重做等功能。
 * 
 */

class CookerZeff
{
public:
    void makeDSX()
    {
        cout << "开始烹饪地三鲜...";
    }
    void makeYXRS()
    {
        cout << "开始烹饪鱼香肉丝...";
    }
    void makeHSPG()
    {
        cout << "开始烹饪红烧排骨...";
    }
    void makeGBJD()
    {
        cout << "开始烹饪宫保鸡丁...";
    }
};

class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* cooker):m_cooker(cooker) {}

    virtual void execute() = 0;
    virtual string name() = 0;
    virtual ~AbstractCommand() {}
protected:
    CookerZeff *m_cooker;
};

class DSXcommand : public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    virtual void execute() override
    {
        m_cooker->makeDSX();
    }
    string name() override
    {
        return "地三鲜";
    }
};

class YXRScommand:public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    virtual void execute() override
    {
        m_cooker->makeYXRS();
    }
    string name() override
    {
        return "鱼香肉丝";
    }
};

class HSPGcommand:public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    virtual void execute() override
    {
        m_cooker->makeHSPG();
    }
    string name() override
    {
        return "红烧排骨";
    }
};

class GBJDcommand:public AbstractCommand
{
public:
    using AbstractCommand::AbstractCommand;
    virtual void execute() override
    {
        m_cooker->makeGBJD();
    }
    string name() override
    {
        return "宫保鸡丁";
    }
};

class WaiterLuffy
{
public:
    // 下单/点餐
    void setOrder(int index, AbstractCommand* command)
    {
        cout << index << "号桌点了" << command->name() << endl;
        if(command->name() == "鱼香肉丝")
        {
            cout << "不好意思，没有鱼香肉丝了~" << endl;
            return;
        }
        if(m_cmdList.find(index)==m_cmdList.end())
        {
            list<AbstractCommand *> mylist;
            mylist.push_back(command);
            m_cmdList[index] = mylist;
        }
        else
        {
            m_cmdList[index].push_back(command);
        }  
    }

    // 撤销订单
    void cancelOrder(int index, AbstractCommand* command)
    {
        if(m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(command);
            cout << index << "号桌, 撤销了" << command->name() << endl;
        }
    }

    // 结账
    void checkOut(int index)
    {
        cout << "第[" << index << "]号桌的顾客点的菜是: 【";
        for (const auto& item : m_cmdList[index])
        {
            cout << item->name();
            if (item != m_cmdList[index].back())
            {
                cout << ",";
            }
        }
        cout << "】" << endl;
    }

    // 发送通知 -> 要求厨师执行某些命令
    void notify(int index)
    {
        for(auto &item : m_cmdList[index])
        {
            item->execute();
            cout << index << "号桌" << endl;
        }
    }
    
private:
    map<int, list<AbstractCommand*>> m_cmdList;
};

int main()
{
    // 厨子
    CookerZeff *cooker = new CookerZeff;
    // 
    DSXcommand  *dsx  = new DSXcommand(cooker);
    YXRScommand *yxrs = new YXRScommand(cooker);
    HSPGcommand *hspg = new HSPGcommand(cooker);
    GBJDcommand *gbjd = new GBJDcommand(cooker);

    WaiterLuffy *luffy = new WaiterLuffy;
    cout << "顾客开始点餐" << endl;
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, hspg);
    luffy->setOrder(1, gbjd);


    luffy->setOrder(2, dsx);
    luffy->setOrder(2, hspg);
    luffy->setOrder(2, gbjd);

    // 一号桌取消了gbjd
    luffy->cancelOrder(1, gbjd);

    cout << "开始下单 ++++++++++++++++" << endl;
    luffy->notify(1);
    luffy->notify(2);
    cout << "结账*******************" << endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    delete cooker;
    delete dsx, gbjd, hspg, yxrs;
    delete luffy;
    return 0;
}