#include <iostream>
#include <vector>
#include "MyList.h"
#include "Iterator.h"
using namespace std;



// 迭代器模式（行为性设计模式）
/*
 * 迭代器模式：是一种行为型设计模式，它使得遍历一个容器对象中的元素变得更加简单。
 *
 * 迭代器模式将 遍历操作 从容器对象（如集合、列表）中分离出来，它通过迭代器对象来
 * 遍历容器对象中的元素，使得遍历操作与容器对象解耦。
 *
 */

int main()
{
    vector<string> nameList = {
        "烬", "奎因", "杰克", "福兹·弗", "X·德雷克",
        "黑色玛利亚", "笹木", "润媞", "佩吉万",
        "一美", "二牙", "三鬼", "四鬼", "五鬼",
        "六鬼", "七鬼", "八茶", "九忍", "十鬼"
    };
    
    MyList ls;
    for (int i = 0; i < nameList.size(); ++i)
    {
        ls.pushBack(nameList.at(i));
    }

    Iterator *it = ls.getIterator(false);
    cout << "节点数：" << ls.getCount() << endl;
    for (it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: 为老大服务!!! " << endl;
    }
    delete it;
    cout << "===================" << endl;

    // 逆序遍历
    it = ls.getIterator(true);
    for (it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: 为老大服务!!! " << endl;
    }
    delete it;


    return 0;
}