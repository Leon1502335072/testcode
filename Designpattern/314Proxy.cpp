#include <iostream>
#include <string>
using namespace std;

// 代理模式（结构型设计模式）
/*
 * 代理模式：该模式通过引入一个新的代理对象Proxy，来间接访问原始对象，从而使访问方式变得灵活和可控
 * 代理对象的设定减少了客户端与真实对象之间的直接交互
 * W是一个抽象接口类
 * ↓
 * A是具体类 B是代理类 A B中都重写了W中的公共接口，A中是真正的方法入口
 * A B是组合关系，B中包含A，其实就是在B的公共接口中调A真正的接口，但是
 * 在调A的接口之前可以做一些逻辑上的处理，来达到想要的效果，有点象hook
 */
class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() {}
};

class RealImage: public Image
{
public:
    RealImage(string filename):m_filename(filename) {}
    void display() override
    {
        cout << "read the image " << m_filename << ".jpg" << endl;
    }

private:
    string m_filename;
};


class ImageProxy: public Image
{
public:
    ImageProxy(string filename)
    :m_filename(filename)
    ,realimage(nullptr) {}

 
    void display() override
    {
        if(realimage == nullptr)
        {
            realimage = new RealImage(m_filename);
        }
        realimage->display();
    }

private:
    RealImage *realimage;
    string m_filename;
};
int main()
{
    Image *image = new ImageProxy("hello");
    image->display();

    return 0;
}