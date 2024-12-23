#include "MyList.h"
#include "Iterator.h"


Node *MyList::insert(Node *node, string name)
{
    Node *item = nullptr;
    if (node = m_head)
    {
        item = pushFront(name);
    }
    else
    {
        item = new Node(name);
        item->next = node;
        item->prev = node->prev;
        node->prev->next = item;
        node->prev = node;
        ++m_count;
    }
    return item;
}
Node *MyList::pushBack(string name)
{
    Node *node = new Node(name);
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}
Node *MyList::pushFront(string name)
{
    Node *node = new Node(name);
    if(m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    ++m_count;
    return node;
}
Iterator *MyList::getIterator(bool isReverse)
{
    Iterator *it = nullptr;
    if (isReverse)
        it = new ReverseIterator(this);
    else
        it = new ForwardIterator(this);
    return it;
}

