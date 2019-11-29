#include <iostream>
#include <filesystem>
#include <chrono>

using namespace std;
using namespace filesystem;
using namespace chrono;

// t1;
//  1'573'443'680 '202'029'390
// -4'864'220'319 '797'970'245
//
// t0:
//  1'573'443'602 '813'273'869
// -4'864'220'397 '186'725'741

//  6'437'663'999

//demo
int main()
{
                // get `now' according to the system_clock and
                // the __file_clock, compute their difference in
                // nanoseconds and seconds:
    auto systemNow = system_clock::now().time_since_epoch();
    auto fileNow = __file_clock::now().time_since_epoch();
    duration diffNano = systemNow - fileNow;
    time_t diff = diffNano.count() / 1'000'000'000;

    cout << "system_clock now: "  << systemNow.count() << "\n"
            "__file_clock now: "  << fileNow.count()   << "\n"
            "difference (nano): " << diffNano.count()  << "\n"
            "difference (secs): " << diff << '\n';

    auto lwt = last_write_time("lastwritetime.cc").time_since_epoch();
    time_t seconds = diff + system_clock::to_time_t(
                            time_point<system_clock>{ nanoseconds(lwt) } );
    cout << "lastwritetime.cc's time: " <<
                put_time(gmtime(&seconds), "%c") << '\n';

    seconds =
        system_clock::to_time_t(time_point<system_clock>{ diffNano });
    cout << "__file_clock's epoch time expressed using the system_clock:\n"
            "       " << put_time(gmtime(&seconds), "%c") << "\n"
            "same, merely using the difference in `now' clock-seconds:\n"
            "       " << put_time(gmtime(&diff), "%c") << '\n';
}
//=
