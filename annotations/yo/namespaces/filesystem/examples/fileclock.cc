#include <iostream>
#include <chrono>
#include <filesystem>

using namespace std;
using namespace filesystem;
using namespace chrono;

//  318315729
// 1403456322 -1085140593
// -1'085'344'473

class FC
{
    struct In
    {
        tm d_tm;
        char const *d_fmt;

        In(tm const &tmData, char const *fmt);
        ostream &insert(ostream &out) const;
    };

    friend ostream &operator<<(ostream &out, In const &in);

    typedef tm (*time_t2tm)(const time_t *);

    typedef time_point<__file_clock>    TPfileClock;
    typedef time_point<system_clock>    TPsystemClock;

    static TPsystemClock const s_sPoint;
    static int const s_offset;

    public:
        enum TimeType
        {
            LT,
            GMT
        };
                    // system time point corresponding to __file_clock
        static TPsystemClock sysTimePoint(TPfileClock const &fp);

                    // tm corresponding to __file_clock for local time
        static tm tmLocal(TPfileClock const &ftp);

                    // tm corresponding to __file_clock for gmtime
        static tm tmGMT(TPfileClock const &ftp);

        static In put_time(TPfileClock const &fp, char const *fmt = "%c",
                    TimeType type = LT);
    private:
        static tm to_tm(tm *(*funPtr)(const time_t *), TPfileClock const &fp);
};

// static data
FC::TPsystemClock const FC::s_sPoint = system_clock::now();

                                        // 'now' expressed for file_clock
int const FC::s_offset = FC::s_sPoint.time_since_epoch().count() -
                         __file_clock::now().time_since_epoch().count();

FC::In::In(tm const &tmData, char const *fmt)
:
    d_tm(tmData),
    d_fmt(fmt)
{}

ostream &FC::In::insert(ostream &out) const
{
    return out << std::put_time(&d_tm, d_fmt);
};

ostream &operator<<(ostream &out, FC::In const &in)
{
    return in.insert(out);
}

FC::In
FC::put_time(TPfileClock const &fp, char const *fmt, TimeType type)
{
    return In{type == LT ? tmLocal(fp) : tmGMT(fp), fmt };
}


//    cout << fc(fPoint) << '\n';

FC::TPsystemClock FC::sysTimePoint(TPfileClock const &fp)
{
    int fnow = fp.time_since_epoch().count();

    fnow += s_offset;               // time according to the system clock

    return s_sPoint + nanoseconds(fnow);
}

tm FC::tmLocal(TPfileClock const &fp)
{
    return to_tm(gmtime, fp);
}

tm FC::tmGMT(TPfileClock const &fp)
{
    return to_tm(localtime, fp);
}

tm FC::to_tm(tm *(*funPtr)(const time_t *), TPfileClock const &fp)
{
    time_t secs = system_clock::to_time_t(
                        sysTimePoint(fp) + nanoseconds{ s_offset }
                    );
    return *(*funPtr)(&secs);
}

time_point<system_clock> conv1(time_point<__file_clock> const &point)
{
    auto systemNow = system_clock::now().time_since_epoch();
    auto fileNow = __file_clock::now().time_since_epoch();

    return time_point<system_clock>{
                nanoseconds(point.time_since_epoch() +
                systemNow - fileNow) };
}

int main()
{
                                        // 'now' expressed for system_clock
    time_point<system_clock> sPoint = system_clock::now();
    int snow = sPoint.time_since_epoch().count();

    cout << "system now in seconds since the epoch: " << snow << '\n';

                                        // current local time
    time_t secs = system_clock::to_time_t(sPoint);
    cout << put_time(localtime(&secs), "%c") << '\n';


                                        // 'now' expressed for file_clock
    time_point<__file_clock> fPoint = __file_clock::now();
    int fnow = fPoint.time_since_epoch().count();

    cout << "file clock now in seconds since the (fc) epoch: " << fnow <<
                                                                        '\n';


    int offset = snow - fnow;        // difference between system- and fileclock
    cout << snow << ' ' << fnow << ' ' << offset << '\n';


    time_point<system_clock> epoch;
    secs = system_clock::to_time_t(epoch);
    cout << "begin of system epoch: secs = " << secs << ", time: " <<
            put_time(gmtime(&secs), "%c") << '\n';

    time_point<system_clock> epochFC{ nanoseconds(-100'000'000'000) };
    secs = system_clock::to_time_t(epochFC);
    cout << "begin of _file_clock epoch: seconds: " << secs << ", time: " <<
            put_time(gmtime(&secs), "%c") << '\n';

    // to go from filesystem_clock to system_clock add offset (expressed in
    // nanoseconds) to the int-count obtained from the filesystem_clock's
    // time_point.

    sPoint += nanoseconds{ offset };

    secs = system_clock::to_time_t(sPoint);
    cout << put_time(localtime(&secs), "%c") << '\n';

    tm tmData{ FC::tmLocal(fPoint) };

    cout << put_time(&tmData, "%c") << '\n';

    cout << FC::put_time(fPoint) << '\n';
}
