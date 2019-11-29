
#include <iostream>
#include <chrono>
#include <filesystem>

using namespace std;
using namespace chrono;
using namespace filesystem;

auto local_time_point(time_point<system_clock> const &tp, char const *fmt)
{
    time_t secs = system_clock::to_time_t( tp );
    return put_time(localtime(&secs), fmt);
}

int main()
{
//    system_clock::duration ds{ 24h };
//    __file_clock::duration df{ 1h };

    system_clock::from_time_t(
        system_clock::to_time_t(
            system_clock::from_time_t(
                12345
            )
        )
    );

        std::time_t tm {time(0)};
        std::cout << std::put_time(std::localtime(&tm), "%c") << '\n';

    time_t secs = system_clock::to_time_t( system_clock::now() );
    cout << put_time(std::localtime(&secs), "%c\n");

    cout << local_time_point(system_clock{}.now(), "%c") << '\n';

//    __file_clock::to_time_t(__file_clock::from_time_t(12345));
    high_resolution_clock::to_time_t(high_resolution_clock::from_time_t(12345));
//    steady_clock::to_time_t(steady_clock::from_time_t(12345));

//    unsigned uval = system_clock::period::num;

//    __file_clock::period rf;


//    system_clock::rep vs;
//    __file_clock::rep vf;

//    system_clock::time_point st = system_clock{}.now();

    __file_clock::time_point ft;
}
