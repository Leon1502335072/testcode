#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
using namespace std;
using json = nlohmann::json;

struct Base
{
    string name;
    int age;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Base, name, age);
};

void
testJsonBase()
{
    string str = R"({"name":"leon", "age":20})";
    // json 对象
    json jsonObj = json::parse(str);
    // cout << "name: " << jsonObj["name"] << ", age: " << jsonObj["age"] << endl;
    // cout << jsonObj.dump() << endl;

    json person;
    person["name"] = "leon";
    person["age"] = 20;
    person["is_student"] = true;
    person["hoby"] = {"programming", "listen to the music", "read book"};
    person["skills"]["C/C++"] = "master";
    person["skills"]["Python"] = "proficiency";
    person["skills"]["C#"] = "proficiency";
    person["skills"]["JavaScript"] = "skilled";
    cout << person.dump(4) << endl;

#if 0
    // 将Json写入文件
    ofstream toFile;
    toFile.open("data.json", ios::out|ios::trunc);
    if (!toFile.is_open())
    {
        cout << "open file error..." << endl;
        return;
    }
    toFile << person.dump(4);
    toFile.close();
#endif

    // 从Json文件读数据
    ifstream fromFile("data.json");
    if(!fromFile.is_open())
    {
        cout << "open file error..." << endl;
        return;
    }
    json jsondata;
    fromFile >> jsondata;
    jsondata.dump(4);
}

void testJson1()
{
    string json_str = R"(
        {
            "name":"Alice",
            "age":20,
            "is_student":true,
            "skills":["C++", "Python", "JavaScript", "C#"]
        }
    )";
    json jsonObj = json::parse(json_str);
    cout << jsonObj.dump() << endl;
    auto name = jsonObj["name"];
    auto age = jsonObj["age"];
    auto isStudent = jsonObj["is_student"];
    vector<string> skills = jsonObj["skills"];

    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    if(isStudent)
    {
        cout << "isStudent: " << "true" << endl;
    }
    else
    {
        cout << "isStudent: " << "false" << endl;
    }
    cout << "skills: ";
    for (unsigned int i = 0; i < skills.size(); ++i)
    {
        if(i == skills.size()-1)
        {
            cout << skills[i];
            break;
        }
        cout << skills[i] << ", ";
    }
    cout << endl;
}


// 遍历Json对象 like STL
void testJson2()
{
    // 从Json文件读数据
    ifstream fromFile("data.json");
    if(!fromFile.is_open())
    {
        cout << "open file error..." << endl;
        return;
    }
    json jsondata;
    // like STL
    fromFile >> jsondata;

    for (auto it = jsondata.begin(); it != jsondata.end(); ++it)
    {
        cout << it.key() << ": " << it.value() << endl;
    }

    cout << endl;
    // 创建json对象直接赋值
    json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {{"everything", 42}}},
        {"list", {1, 0, 2}},
        {"object", {{"currency", "USD"}, {"value", 42.99}}}};
    cout << j2.dump(4) << endl;

}

// 几种创建json对象的形式
void testJson3()
{
    // 不能打印出json格式
    json j = "{\"pi\":3.141, \"happy\":true}";
    // 直接创建json对象的方式 并可以打印出json格式
    json j1 = {
        {"pi", 3.141},
        {"happy", true}};
    json j2 = "{\"pi\":3.141, \"happy\":true}"_json;
    json j3 = R"({"pi":3.14, "happy":true})"_json;
    cout << j.dump(4) << endl;
    cout << j1.dump(4) << endl;
    cout << j2.dump(4) << endl;
    cout << j3.dump(4) << endl;
    // 还有就是通过创建string对象，然后在用json的解析函数解析string对象得到 json对象 就像第一个测试函数testJsonBase中的那样
}

// STL-like access
void testJson4()
{
    // create an array using push_back
    json j;
    j.push_back("foo");
    j.push_back(1);
    j.push_back(true);

    // also use emplace_back
    j.emplace_back(1.78);

    // iterate the array
    for (json::iterator it = j.begin(); it != j.end(); ++it) 
    {
        std::cout << *it << '\n';
    }

    // range-based for
    for (auto& element : j) 
    {
        std::cout << element << '\n';
    }

    // getter/setter
    const auto tmp = j[0].template get<std::string>();
    j[1] = 42;
    bool foo = j.at(2);

    // comparison
    j == R"(["foo", 1, true, 1.78])"_json;  // true

    // other stuff
    j.size();     // 4 entries
    j.empty();    // false
    j.type();     // json::value_t::array
    j.clear();    // the array is empty again

    // convenience type checkers when j = ["foo", 1, true, 1.78]
    auto v1 = j.is_null();         // false
    auto v2 = j.is_boolean();      // false
    auto v3 = j.is_number();       // false
    auto v4 = j.is_object();       // false
    auto v5 = j.is_array();        // true
    auto v6 = j.is_string();       // false

    // create an object
    json o;
    o["foo"] = 23;
    o["bar"] = false;
    o["baz"] = 3.141;

    // also use emplace 添加键值对 weather:sunny
    o.emplace("weather", "sunny");

    // special iterator member functions for objects
    for (json::iterator it = o.begin(); it != o.end(); ++it) 
    {
        std::cout << it.key() << " : " << it.value() << "\n";
    }

    // the same code as range for
    for (auto& el : o.items()) 
    {
        std::cout << el.key() << " : " << el.value() << "\n";
    }

    // even easier with structured bindings (C++17)
    for (auto& [key, value] : o.items()) 
    {
        std::cout << key << " : " << value << "\n";
    }

    // find an entry
    if (o.contains("foo")) 
    {
        // there is an entry with key "foo"
    }

    // or via find and an iterator
    if (o.find("foo") != o.end()) 
    {
        // there is an entry with key "foo"
    }

    // or simpler using count()
    int foo_present = o.count("foo"); // 1
    int fob_present = o.count("fob"); // 0

    // delete an entry
    o.erase("foo");
}

// 从STL容器构造
void testJson5()
{
    std::vector<int> c_vector {1, 2, 3, 4};
    json j_vec(c_vector);
    // [1, 2, 3, 4]

    std::deque<double> c_deque {1.2, 2.3, 3.4, 5.6};
    json j_deque(c_deque);
    // [1.2, 2.3, 3.4, 5.6]

    std::list<bool> c_list {true, true, false, true};
    json j_list(c_list);
    // [true, true, false, true]

    // 单项链表 forward_list
    std::forward_list<int64_t> c_flist {12345678909876, 23456789098765, 34567890987654, 45678909876543};
    json j_flist(c_flist);
    // [12345678909876, 23456789098765, 34567890987654, 45678909876543]

    std::array<unsigned long, 4> c_array {{1, 2, 3, 4}};
    json j_array(c_array);
    // [1, 2, 3, 4]

    std::set<std::string> c_set {"one", "two", "three", "four", "one"};
    json j_set(c_set); // only one entry for "one" is used
    // ["four", "one", "three", "two"]

    std::unordered_set<std::string> c_uset {"one", "two", "three", "four", "one"};
    json j_uset(c_uset); // only one entry for "one" is used
    // maybe ["two", "three", "four", "one"]

    std::multiset<std::string> c_mset {"one", "two", "one", "four"};
    json j_mset(c_mset); // both entries for "one" are used
    // maybe ["one", "two", "one", "four"]

    std::unordered_multiset<std::string> c_umset {"one", "two", "one", "four"};
    json j_umset(c_umset); // both entries for "one" are used
    // maybe ["one", "two", "one", "four"]

    //==========================================================================

    // 红黑树 有序 key唯一
    std::map<std::string, int> c_map { {"one", 1}, {"two", 2}, {"three", 3} };
    json j_map(c_map);
    // {"one": 1, "three": 3, "two": 2 } 
    
    // 哈希表 无序 key唯一
    std::unordered_map<const char*, double> c_umap { {"one", 1.2}, {"two", 2.3}, {"three", 3.4} };
    json j_umap(c_umap);
    // {"one": 1.2, "two": 2.3, "three": 3.4} 

    // 红黑树 有序 key不唯一  => 容器中有重复的键值但是生成json后不允许有重复的键值
    std::multimap<std::string, bool> c_mmap { {"one", true}, {"two", true}, {"three", false}, {"three", true} };
    json j_mmap(c_mmap); // only one entry for key "three" is used
    // maybe {"one": true, "two": true, "three": true}
    

    // 哈希表 无序 key不唯一 => 容器中有重复的键值但是生成json后不允许有重复的键值
    std::unordered_multimap<std::string, bool> c_ummap { {"one", true}, {"two", true}, {"three", false}, {"three", true} };
    json j_ummap(c_ummap); // only one entry for key "three" is used
    // maybe {"one": true, "two": true, "three": true}
    
}

// JSON Pointer and JSON Patch
void testJson6()
{
    // a JSON value
    json j_original = R"(
        {
            "baz": ["one", "two", "three"],
            "foo": "bar"
        }
    )"_json;

    // access members with a JSON pointer (RFC 6901)
    j_original["/baz/1"_json_pointer];
    // "two"

    // a JSON patch (RFC 6902) 其实是定义了一组操作
    // 取代/替换，键是baz，值改为boo
    json j_patch = R"([
    { "op": "replace", "path": "/baz", "value": "boo" },
    { "op": "add", "path": "/hello", "value": ["world"] },
    { "op": "remove", "path": "/foo"}
    ])"_json;

    // apply the patch 得到补丁后的结果
    json j_result = j_original.patch(j_patch);
    // {
    //    "baz": "boo",
    //    "hello": ["world"]
    // }

    // calculate a JSON patch from two JSON values
    auto j_diff = json::diff(j_result, j_original);
    // [
    //   { "op":" replace", "path": "/baz", "value": ["one", "two", "three"] },
    //   { "op": "remove","path": "/hello" },
    //   { "op": "add", "path": "/foo", "value": "bar" }
    // ]
    // cout << j_diff.dump(4) << endl;


    //merge patch 合并补丁
    json j_new_config = {
        {"name", "modbus"},
        {"config", {{"type", ""}, {"startIndex", 0}}},
        {"head", 10}
    };
    cout << j_new_config.dump(4) << endl;

    json j_old_config = {
        {"name", "modbus"},
        {"config", {{"type", "floatlh"}, {"startIndex", 17}}}};
    cout << j_old_config.dump(4) << endl;

    // 新的合并旧的
    j_new_config.merge_patch(j_old_config);
    cout << j_new_config.dump(4) << endl;

    // 就得合并新的
    j_old_config.merge_patch(j_new_config);
    cout << j_old_config.dump(4) << endl;
    // 结论是无论是谁合并谁结果都是一样的，也就是二者取并集，然后哪些默认值比如""、0 啊这些会被有值的替换掉
}

// 任意类型转换
void testJson7()
{
    string s1 = "hello world";
    // string -> json 支持隐式转换
    json j1 = s1;
    // 反过来不推荐直接写 应该是下面这种
    auto s2 = j1.template get<string>();

    ifstream f;
    f.open("../.vscode/tasks.json");
    json jsonfile;
    if (f.is_open())
    {
        jsonfile << f;
    }
    else
    {
        cout << "open file error..." << endl;
    }
    cout << jsonfile.dump(4) << endl;
}

int main(int arg, char* argv[])
{
    // testJsonBase();
    // testJson1();
    // testJson2();
    // testJson3();
    // testJson4();
    // testJson5();
    // testJson6();
    testJson7();
    cout << endl;
    return 0;
}