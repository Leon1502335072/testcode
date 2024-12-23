// cppcheck-suppress-file unusedFunction 
#include <iostream>

int fun(int a, int b)
{
    if(a>b)
    {
        std::cout << "较大数是: " << a << std::endl;
        return a;
    }
    else if(a<b)
    {
        std::cout << "较大数是: " << b << std::endl;
        return b;
    }
}


int main()
{
    return 0;
}