#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // capacity容器的容量，size元素的数量
    vector<int> arr(10, 1);
    cout << "arr.capacity(): " << arr.capacity() << "   arr.size(): " << arr.size() << endl;

    arr.reserve(15);
    cout << "after arr.reserve(15):" << endl;
    cout << "arr.capacity(): " << arr.capacity() << "   arr.size(): " << arr.size() << endl;

    arr.reserve(8);
    cout << "after arr.reserve(8):"<< endl;
    cout << "arr.capacity(): " << arr.capacity() << "   arr.size(): " << arr.size() << endl;

    arr.resize(13); //resize有两个参数，第二个不传默认为0
    cout << "after arr.resize(13): "<< endl;
    cout << "arr.capacity(): " << arr.capacity() << "   arr.size(): " << arr.size() << endl;

    arr.resize(5); //resize有两个参数，第二个不传默认为0
    cout << "after arr.resize(5): "<< endl;
    cout << "arr.capacity(): " << arr.capacity() << "   arr.size(): " << arr.size() << endl;

    return 0;
}