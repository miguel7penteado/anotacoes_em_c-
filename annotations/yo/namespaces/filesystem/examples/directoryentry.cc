//de
#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(int argc, char **argv) // provide 2 arguments
{
    directory_entry de{ argv[1] };
    cout << de.path() << '\n';

    de.replace_filename(argv[2]);
    cout << de.path() << '\n';

    de.assign(argv[2]);
    cout << de.path() << '\n';
}
//=
