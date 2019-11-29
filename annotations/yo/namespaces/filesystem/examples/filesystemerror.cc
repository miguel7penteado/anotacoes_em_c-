#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

//fse
int main()
try
{
    try
    {
        throw filesystem_error{ "exception encountered", "p1", "p2",
                                    make_error_code(errc::address_in_use) };
    }
    catch (filesystem_error const &fse)
    {
        cerr << "what:  " << fse.what() << "\n"
                "path1: " << fse.path1() << "\n"
                "path2: " << fse.path2() << "\n"
                "code:  " << fse.code() << '\n';

        throw;
    }
}
catch (exception const &ec)
{
    cerr << "\n"
            "plain exception's what: " << ec.what() << "\n\n";
}
//=
