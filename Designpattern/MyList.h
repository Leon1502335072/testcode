#ifndef __MYLIST_H__
#define __MYLIST_H__

#include <iostream>
#include <string>
using namespace std;

class Iterator;

struct Node
{
    Node(string val):name(val), next(nullptr), prev(nullptr) {}
    string name;
    Node *next;
    Node *prev;
};

class MyList
{
public:
    inline int getCount() { return m_count; }
    inline Node *head() { return m_head; }
    inline Node *tail() { return m_tail; }

    Node *insert(Node *node, string name);
    Node *pushBack(string name);
    Node *pushFront(string name);

    Iterator *getIterator(bool isReverse = true);

private:
    Node *m_head = nullptr;
    Node *m_tail = nullptr;
    int m_count = 0;
};

#endif