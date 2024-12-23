#include <iostream>
#include <bits/stdc++.h>

// 组合模式（结构型模式） 特点就像一棵树
/*
 * 组合模式是一种结构型设计模式，该模式将对象组合成树状结构，以便于分层和统一管理。
 * Linux的文件系统就是一个典型的案例，除此之外就是在非叶节点中需要提供一个容器来保
 * 存叶子结点和非叶节点，其最大的特点就是一棵树
 * 
 */

// 抽象节点
class FileSystemComponent 
{
public:
    virtual void display() const = 0;
};

// 文件/ 也就是叶子结点
class File : public FileSystemComponent 
{
public:
    File(const std::string& name, int size)
        :name(name), size(size) {}
     
    void display() const override
    {
        std::cout << "File: " << name <<
            " (" << size << " bytes)" <<
             std::endl;
    }
private:
    std::string name;
    int size;
};


// 目录类/非叶节点
class Directory : public FileSystemComponent 
{
public:
    Directory(const std::string& name)
                        :name(name) {}
    
    // 这点需要递归
    void display() const override
    {
        std::cout << "Directory: " << name << std::endl;
        for (const auto& component : components) 
        {
            component->display();
        }
    }
    void addComponent(FileSystemComponent* component)
    {
        components.push_back(component);
    }
private:
    std::string name;
    std::vector<FileSystemComponent*> components;
};

int main()
{
    FileSystemComponent* file1
        = new File("document.txt", 1024);
    FileSystemComponent* file2
        = new File("image.jpg", 2048);

    Directory* directory = new Directory("My Documents");

    directory->addComponent(file1);
    directory->addComponent(file2);

    directory->display();
    return 0;
}