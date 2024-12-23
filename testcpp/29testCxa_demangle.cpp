#include <iostream>
#include <cxxabi.h>
#include <string>
#include <map>

template <class T>
const char *TypeToName() 
{
    static const char *s_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
    return s_name;
}

struct base
{
    int a;
    std::string str;
    std::map<int, std::string> m_map;
};

int
main()
{
    const char* mangled_name = "_ZNK4TestEv";
    int status = 0;
    char* demangled_name = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);
 
    if (status == 0) 
    {
        std::cout << "Demangled name: " << demangled_name << std::endl;
        free(demangled_name); // 使用完毕后需要释放内存
    } 
    else 
    {
        std::cout << "Failed to demangle" << std::endl;
    }
    std::cout << "--------------------------" << std::endl;

    base b;
    std::map<int, std::string> m_map;
    //const char *buff = TypeToName<b>();
    std::cout << abi::__cxa_demangle(typeid(m_map).name(), nullptr, nullptr, nullptr) << std::endl;
    //std::cout << buff << std::endl;
    return 0;
}