#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    path p{ "absolute.cc" };

    cout << "Current path is " << current_path() << '\n' <<
            "Absolute path for " << p << " is " << absolute(p) << '\n';
}
