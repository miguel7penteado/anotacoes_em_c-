#include <chrono>
#include <filesystem>
#include <iostream>

using namespace std;
using namespace chrono;
using namespace filesystem;

int main()
{
    time_point<system_clock, nanoseconds> tp;
    time_point<system_clock, seconds> tp2;
    tp2 += seconds(5);

//    to_time_t(tp);

    time_point<system_clock, hours> minpoint  =
                        time_point<system_clock, hours>::min();

    cout << minpoint.time_since_epoch().count() << '\n';

    cout <<
        time_point<system_clock, hours>::min().time_since_epoch().count() <<
        '\n';

//    time_point<system_clock, milliseconds> tp3{ tp2 };
    time_point<system_clock, milliseconds> tp3{
        time_point<system_clock, seconds>{} += seconds{ 5 } };

    cout << tp3.time_since_epoch().count() << '\n';


//            time_point<system_clock, milliseconds>{} + 1s };

}
