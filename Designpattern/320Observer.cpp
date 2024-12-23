#include <iostream>
#include "NewsAgency.h"
#include "Observer.h"
using namespace std;

// 观察者模式（行为型设计模式） 又叫 发布订阅模式 类似于redis中的发布订阅模式

/*
 * 观察者模式是一种行为型设计模式，又被称为"发布-订阅"模式，它定义了对象之间的一对多的
 * 依赖关系，当一个对象的状态发生变化时，所有依赖于它的对象都会收到通知并自动更新。
 * 
 * A 是观察者类（订阅人），B 是频道类（发布消息的人）
 * A中有B类型的指针（成员变量），通过B的对象A可以订阅或者退订B，B中有装A的容器，当B发布消息时
 * 会循环容器 把消息发给每一个A的对象，当然发布消息是通过调A类内部的接收消息的接口实现的。
 * A 与 B 是一种相互关联的关系
 * 
 */

#if 1
int main()
{
    // 发布者
    NewsAgency* news1 = new Morgans;
    NewsAgency* news2 = new Gossip;
    // 观察者(订阅者)
    Dragon* dragon = new Dragon(news1, "蒙奇·D·龙");
    Shanks* shanks = new Shanks(news1, "香克斯");
    Bartolomeo* barto = new Bartolomeo(news2, "巴托洛米奥");
    // 由发布者推送消息
    news1->notify("蒙奇·D·路飞成为新世界的新的四皇之一, 赏金30亿贝里!!!");
    cout << "=====================" << endl;
    news2->notify("女帝汉库克想要嫁给路飞, 给路飞生猴子, 哈哈哈...");

    delete news1;
    delete news2;
    delete dragon;
    delete shanks;
    delete barto;

    return 0;
}
#endif