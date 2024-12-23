#include <iostream>
#include "include/gmock/gmock.h"

class Person
{
public:
    virtual int get(const int id, const string &name) = 0;
};

class mockPerson
{
protected:
    MOCK_METHOD(get, )
    
};

int main(int argc, char** argv)
{

    return 0;
}