#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void durationtest()
{
    // 定义一个 小时 的时间周期 hour
    duration<int, ratio<3600, 1>> hour(1);
    chrono::hours h(1); 

    // 定义一个 分钟 的时间周期 min
    duration<int, ratio<60, 1>> min(1);
    chrono::minutes m(1);

    // 秒
    duration<int, ratio<1, 1>> sec(1);
    chrono::seconds s(1);
    // 毫秒
    duration<int, ratio<1, 1000>> misec(1);
    // 微秒
    duration<int, ratio<1, 1000000>> micrsec(1);
    // 纳秒
    duration<int, ratio<1, 1000000000>> nsec(1);

    cout << "===============================" << endl;
    chrono::minutes m1(9);
    chrono::minutes m2(8);
    m1++;
    m2--;
    chrono::minutes m3 = m1 - m2;
    cout << "m3 count: " << m3.count() << endl;
    duration<int, ratio<60, 1>> t1(10);
    duration<int, ratio<1, 1>> t2(60);
    duration<int, ratio<1, 1>> t3 = t1 - t2;

    duration<double, ratio<9, 7>> d1(3);
    duration<double, ratio<6, 5>> d2(1);
    duration<double, ratio<3, 35>> d3 = d1 - d2;

    cout << "t3 count: " << t3.count() << endl;
    cout << "d3 count: " << d3.count() << endl;

}

void clocktest()
{
    // 创建一个时间点对象 这个epoch里面存的时间点事1970-01-01 08:00:00
    system_clock::time_point epoch;
    // 10天的时间段
    duration<int, ratio<3600, 1>> tenDays(10 * 24);

    system_clock::time_point epoch1 = epoch + tenDays; //1970-01-11 08:00:00
    system_clock::time_point epoch2(epoch + tenDays); //1970-01-11 08:00:00

    // 拿到当前时间
    system_clock::time_point nowTime = system_clock::now();
    // 得到从1970-01-01 08:00:00 到nowTime的总秒数
    time_t sec = system_clock::to_time_t(nowTime);
    cout << "时间格式化后：" << ctime(&sec) << endl;

    system_clock::time_point nw = system_clock::from_time_t(sec);
}
void steadyClockTest()
{
    auto t1 = steady_clock::now();
    for (int i = 0; i < 1000; ++i)
    {
        cout << "*";
    }
    auto t2 = steady_clock::now();
    
    // t3 是 duration<int, ratio<1, 1000000000>> 纳秒
    auto t3 = t2 - t1;
    cout << endl;
    // 两种转换秒的方式
    cout << "循环所用时间为：" << (double)t3.count()/1000000000 << endl;
    // d和t3的类型和ratio都不相同 所以要使用duration_cast！！！
    duration<double, ratio<1, 1>> d = duration_cast<duration<double, ratio<1, 1>>>(t3);
    cout << "循环所用时间为：" << d.count() << endl;
}

void durationCastTest()
{
    // 分钟 -> 小时
    hours h = duration_cast<hours>(minutes(60));
    // 小时 -> 分钟
    minutes m1 = hours(1);

    // 浮点 -> 整形
    using mydouble = duration<double>;
    seconds ss = duration_cast<seconds>(duration<double>(2.5));
    // 整形 -> 浮点
    mydouble dd = seconds(9);

    duration<int, ratio<1, 100>> t1(100);
    duration<double, ratio<1, 1000>> t2(12.56);

    duration<int, ratio<1, 100>> t3 = duration_cast<duration<int, ratio<1, 100>>>(t2);
    duration<double, ratio<1, 1000>> t4 = t1;
}

template <class T>
using myTimePoint = time_point<system_clock, T>;

int main(int arg, char* argv[])
{
    myTimePoint<seconds> sec(seconds(1));
    myTimePoint<milliseconds> millsec(milliseconds(1));

    myTimePoint<milliseconds> temp1 = sec;
    // 毫秒转秒 丢失精度不允许
    // myTimePoint<seconds> temp2 = millsec;
    myTimePoint<seconds> temp2 = time_point_cast<seconds>(millsec);
    return 0;
}