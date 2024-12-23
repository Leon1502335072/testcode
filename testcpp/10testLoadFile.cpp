#include <iostream>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <signal.h> // for kill()
#include <sys/syscall.h>
#include <sys/stat.h>
#include <execinfo.h> // for backtrace()
#include <cxxabi.h>   // for abi::__cxa_demangle()
#include <algorithm>  // for std::transform()
#include <vector>
#include <string>
using namespace std;

void ListAllFile(std::vector<std::string> &files, const std::string &path, const std::string &subfix) 
{
    // access用于检查文件的权限 参数0表示只检查文件是否存在
    if (access(path.c_str(), 0) != 0) 
    {
        return;
    }
    // opendir函数： opendir 用于打开一个目录，并返回一个指向目录的指针（称为目录流）
    DIR *dir = opendir(path.c_str());
    if (dir == nullptr) 
    {
        return;
    }
    // dp用来保存读到的目录里的每一项
    struct dirent *dp = nullptr;
    // 逐条读取目录中的文件 信息存在dp中
    while ((dp = readdir(dir)) != nullptr) 
    {
        // 该条是目录
        if (dp->d_type == DT_DIR) 
        {
            if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) 
            {
                continue;
            }
            // 递归找
            ListAllFile(files, path + "/" + dp->d_name, subfix);
        }  
        else if (dp->d_type == DT_REG) // 该条是一个普通文件
        {
            // dp->d_name 读到的文件过着目录的名字，不加路径
            std::string filename(dp->d_name);
            // 如果查找标志为空 即所有的普通文件都符合 -> 路径+文件名添加到vector 
            if (subfix.empty()) 
            {
                files.push_back(path + "/" + filename);
            } 
            else 
            {
                // 如果文件名+后缀的大小都小于 ".yml" 一定不是
                if (filename.size() < subfix.size()) 
                {
                    continue;
                }
                // 再判断是否是".yml"文件 filename.substr() 的返回值是一个被截取的字符串，而filename本身并没有改变
                if (filename.substr(filename.length() - subfix.size()) == subfix) 
                {
                    files.push_back(path + "/" + filename);
                }
            }
        }
    }
    closedir(dir);
}


main()
{
    vector<string> files;
    // 拿到的是绝对路径
    ListAllFile(files, "/testcode/testcpp", ".yaml");
    for (int i = 0; i < files.size(); ++i)
    {
        cout << files[i] << endl;
    }
    return 0;
}