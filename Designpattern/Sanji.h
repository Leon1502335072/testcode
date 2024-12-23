#ifndef __SANJI_H__
#define __SANJI_H__
#include <iostream>
#include "State.h"

class SanJi
{
public:
    SanJi()
    {
        // 赋值一个早上的状态
        m_state = new ForenoonState;
    }
    void working()
    {
        m_state->working(this);
    }

    void setState(AbstractState* state)
    {
        if(m_state)
        {
            delete m_state;
            m_state = nullptr;
        }
        m_state = state;
    }
    void setClock(int clock)
    {
        m_clock = clock;
    }

    int getClock() { return m_clock; }

private:
    int m_clock = 0;
    AbstractState *m_state = nullptr;
};

#endif