#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <map>
using namespace std;


class oper
{
public:
	bool operator()(const string& ch1, const string& ch2)
	{
		return strcasecmp(ch1.c_str(), ch2.c_str()) < 0;
	}
};



int main()
{
    map<string, string, oper> myMap;
    myMap["Connection"] = "hello Connection";
    if(myMap.find("connection")!=myMap.end())
    {
        cout << "zhaodaole" << endl;
    }

    return 0;
}