#include <iostream>
#include <yaml-cpp/yaml.h>
using namespace std;

static void ListAllMember(const std::string &prefix, const YAML::Node &node, 
                          std::list<std::pair<std::string, const YAML::Node>> &output) 
{
    // 命名不合法 find_first_not_of大小写不敏感
    std::cout << prefix << std::endl;
    if (prefix.find_first_not_of("abcdefghikjlmnopqrstuvwxyz._012345678") != std::string::npos)
    {
        std::cout << "Illegal name definition! " << std::endl;
        return;
    }
    output.push_back(std::make_pair(prefix, node));
    // 如果node是一个map
    if (node.IsMap()) 
    {
        for (auto it = node.begin(); it != node.end(); ++it)      
        {
            // 递归提取键和值
            ListAllMember(prefix.empty() ? it->first.Scalar()
                                         : prefix + "." + it->first.Scalar(),
                          it->second, output);
        }
    }
}


int main()
{
    //YAML::Node node = YAML::LoadFile("/Coroutines/sylar-from-scratch/bin/conf/test_config.yml");
    YAML::Node node = YAML::LoadFile("/testcode/testcpp/test1.yaml");
    
    // std::cout << node["name"].as<std::string>() << std::endl;
    // std::cout << node["sex"].as<std::string>() << std::endl;
    // std::cout << node["age"].as<int>() << std::endl;
    // std::cout << node["system"]["port"].as<int>() << std::endl;
    // std::cout << node["system"]["value"].as<int>() << std::endl;
    // std::cout << node["system"]["web"].as<std::string>() << std::endl;
    // std::cout << node["system"]["ip"].as<std::string>() << std::endl;
    // for (auto it = node["system"]["int_vec"].begin(); it != node["system"]["int_vec"].end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    std::list<std::pair<std::string, const YAML::Node>> output;
    ListAllMember("", node, output);
    for(auto& i : output )
    {
        if(i.first.empty())
        {
            std::cout << "首项" << std::endl;
        }
        else
        {
            std::cout << i.first << std::endl;
        }
        
    }

    
    return 0;
}