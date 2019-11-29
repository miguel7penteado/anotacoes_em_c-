//#define XERR
#include "main.ih"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"replace", 'r'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("hrv", longOpts, longEnd, argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 1);

    Compactor compactor;
    compactor.run();
}
catch (int value)
{
    return Arg::instance().option("hv") ? 0 : value;
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}
catch (...)
{
    return 1;
}
