#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "MyList.h"

class Iterator
{
public:
    Iterator(MyList* list): m_list(list) {}
    inline Node* current()
    {
        return m_current;
    }
    virtual Node *first() = 0;
    virtual Node *next() = 0;
    virtual bool isDone() = 0;

protected:
    MyList *m_list = nullptr;
    Node *m_current = nullptr;
};

class ForwardIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node *first() override
    {
        m_current = m_list->head();
        return m_current;
    }
    Node *next() override
    {
        m_current = m_current->next;
        return m_current;
    }
    bool isDone() override 
    { 
        return m_current == m_list->tail()->next; 
    }
};

class ReverseIterator : public Iterator
{
public:
    using Iterator::Iterator;
    Node *first() override
    {
        m_current = m_list->tail();
        return m_current;
    }
    Node *next() override
    {
        m_current = m_current->prev;
        return m_current;
    }
    bool isDone() override 
    { 
        return m_current == m_list->head()->prev; 
    }
};

#endif