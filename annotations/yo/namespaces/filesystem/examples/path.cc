#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    path p{ "/abs/olu/te.cc" };


    p.replace_filename("this/part");

    cout << "Current path is " << current_path() << '\n' <<
                 "Absolute path for " << p << " is " << absolute(p) << '\n';

    cout << absolute("tmp/filename") << '\n';

    p /= "extension";
    cout << p << '\n';

    cout << path{}.append("entry") << '\n';

    cout << p.replace_extension("out") << '\n';
    cout << p.replace_extension(".out") << '\n';
}
