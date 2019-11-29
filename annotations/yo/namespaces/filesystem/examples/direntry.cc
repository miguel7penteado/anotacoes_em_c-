#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    directory_entry one;

    one = directory_entry{ "one" };

    one = one;

    cout << (one == directory_entry( "one" )) << '\n';

    directory_iterator("/home")->status();

    cout << *directory_iterator{ "/home" } << '\n';

    directory_iterator dir;

    filesystem::begin( directory_iterator{ "/home" } );
    filesystem::end( directory_iterator{ "/home" } );

    for (directory_entry const &de: directory_iterator{ "/home" })
        cout << de << '\n';

}
