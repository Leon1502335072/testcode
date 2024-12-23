#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_LEVEL 16

template <class T>
struct Node
{
    T val;
    vector<Node<T> *> forward;
    Node(T v, int level):val(v), forward(level, nullptr) {}
};

template <class T>
class SkipList
{
private:
    int level;
    Node<T> *head;

public:
    SkipList() : level(1)
    {
        head = new Node<T>(T(), MAX_LEVEL);
    }

    // 生成随机层数
    int randomLevel()
    {
        int lvl = 1;
        srand(time(0));
        while ((rand() % 2 == 0) && lvl <= MAX_LEVEL)
        {
            lvl++;
        }
        return lvl;
    }

    // 插入元素
    void insert(const T& data)
    {
        vector<Node<T> *> update(MAX_LEVEL, nullptr);
        auto current = head;

        // 查找每一层的插入点
        for (int i = level - 1; i >= 0; --i)
        {
            while(current->forward[i] != nullptr && current->forward[i]->val < data )
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();
        if(newLevel > level)
        {
            for (int i = level; i < newLevel; ++i)
            {
                update[i] = head;
            }
            level = newLevel;
        }

        // 开始插入
        Node<T> *newNode = new Node<T>(data, newLevel);
        for (int i = 0; i < level; ++i)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool search(const T& data)
    {
        auto current = head;
        for (int i = level - 1; i >= 0; --i)
        {
            while(current->forward[i] != nullptr && current->forward[i]->val < data)
            {
                current = current->forward[i];
            }
        }

        // 来到第0层
        if(current->forward[0] != nullptr && current->forward[0]->val == data)
        {
            cout << "This data exists." << endl;
            return true;
        }

        cout << "This data does not exist." << endl;
        return false;
    }

    void remove(const T& data)
    {
        vector<Node<T> *> update(MAX_LEVEL, nullptr);
        auto current = head;

        for (int i = level - 1; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->val < data)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        //判断节点是否存在
        if(current->forward[0] != nullptr && current->forward[0]->val == data)
        {
            current = current->forward[0];
            for (int i = level - 1; i >= 0; --i)
            {
                if(update[i]->forward[i] != current)
                {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            // 如果删除的是最大层的节点层数要减少
            while (level > 1 && head->forward[level - 1] == nullptr)
            {
                level--;
            }
        }

        delete current;
    }

    // 打印
    void printSkipList()
    {
        for (int i = level - 1; i >= 0; --i)
        {
            auto cur = head->forward[i];
            cout << "Level " << i << ": ";
            while(cur != nullptr)
            {
                cout << cur->val << " ";
                cur = cur->forward[i];
            }
            cout << endl;
        }
        cout << "-----------------------------" << endl;
    }
};

int main(int arg, char* argv[])
{
    SkipList<int> skiplist;
    skiplist.insert(3);
    skiplist.insert(66);
    skiplist.insert(17);
    skiplist.insert(9);
    skiplist.insert(12);
    skiplist.printSkipList();

    skiplist.search(17);
    skiplist.search(18);

    skiplist.remove(17);
    skiplist.printSkipList();

    return 0;
}