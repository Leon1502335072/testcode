#include <iostream>


class Noncopyable
{
public:
    Noncopyable() = delete;
    ~Noncopyable() = delete;
    Noncopyable(const Noncopyable &val) = delete;
    Noncopyable(const Noncopyable &&val) = delete;
    Noncopyable &operator=(const Noncopyable &) = delete;
};


class Base : public Noncopyable
{
public:
    Base() {}
    ~Base() {}
};

Base fun()
{
    Base b;
    return b;
}

int main()
{
    Base b;
    //Base b1(b); // 不允许
    // Base b1 = b; // 不允许
    Base b2(std::move(b));
    return 0;
}