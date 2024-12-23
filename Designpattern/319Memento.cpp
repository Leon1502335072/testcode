#include <iostream>
#include <map>
#include <vector>
using namespace std;


// 备忘录模式（行为型设计模式）

/*
 * 备忘录模式是一种行为型设计模式，它允许将对象的状态保存在外部，并在需要时恢复。
 *
 * 备忘录模式允许在不破坏封装性的前提下，捕获并存储一个对象的内部状态，并在需要时将其恢复到之前的状态。
 * 
 * A 是备忘录类，B是一个发起人类，内部可以创建 A的对象， C 是管理A对象的类
 * 
 * 现在当B运行到某一状态时可以通过内部的接口 将此时B的状态创建成A的对象，然后将对象保存在C中（C内部的容器）
 * 当想要回到B的某种状态时从C中取出A的对象，然后B调自己内部加载的接口将B加载成那种状态即可
 * 
 */



// 数据类
class History
{
public:
    History(string msg) : m_msg(msg) {}
    string getHistory()
    {
        return m_msg;
    }
private:
    string m_msg;
};

// 事件的亲历者 - 脚盆鸡
class JiaoPenJi
{
public:
    // 脚盆鸡做的事情
    void setState(string msg)
    {
        m_msg = msg;
    }
    // 记录历史 - 封装数据
    History* saveHistory()
    {
        return new History(m_msg);
    }
    // 得到历史信息 -> 不负责加载历史信息, 具体的加载动作是有记录者对象完成的
    void getStateFromHistory(History* history)
    {
        m_msg = history->getHistory();
    }
    string getState()
    {
        return m_msg;
    }
    // 被打
    void beiDaddyDa()
    {
        cout << "脚盆鸡被兔子狠狠地揍了又揍, 终于承认了它们之前不承认的这些罪行: " << endl;
    }
private:
    string m_msg;
};

// 事件(数据)的记录者
class Recorder
{
public:
    void addHistory(int index, History* history)
    {
        m_history.insert(make_pair(index, history));
    }
    History* getHistory(int index)
    {
        if (m_history.find(index) != m_history.end())
        {
            return m_history[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_history;
};

#if 1
int main()
{
    vector<string> msg{
        "不承认偷了中国的中医!!!",
        "不承认发动了侵华战争!!!",
        "不承认南京大屠杀!!!!",
        "不承认琉球群岛和钓鱼岛是中国的领土!!!",
        "不承认731部队的细菌和人体试验!!!",
        "不承认从中国掠夺的数以亿计的资源和数以万计的文物!!!",
        "我干的龌龊事儿罄竹难书, 就是不承认......"
    };
    JiaoPenJi* jiaopen = new JiaoPenJi;
    Recorder* recorder = new Recorder;
    for (int i = 0; i < msg.size(); ++i)
    {
        jiaopen->setState(msg.at(i));
        recorder->addHistory(i, jiaopen->saveHistory());
    }
    jiaopen->beiDaddyDa();
    for (int i = 0; i < msg.size(); ++i)
    {
        jiaopen->getStateFromHistory(recorder->getHistory(i));
        cout << "   --  " << jiaopen->getState() << endl;
    }
    return 0;
}
#endif