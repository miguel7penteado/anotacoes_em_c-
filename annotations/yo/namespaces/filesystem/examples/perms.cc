#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    path perm{ "perms.cc" };

    auto stat = status(perm);

    cout << oct << "permissions: " <<
                    static_cast<size_t>(stat.permissions()) << '\n';

    permissions(perm, perms::owner_write, perm_options::remove);

    stat = status(perm);

    cout << oct << "permissions: " <<
                    static_cast<size_t>(stat.permissions()) << '\n';

    permissions(perm, perms::owner_write, perm_options::add);

    stat = status(perm);

    cout << oct << "permissions: " <<
                    static_cast<size_t>(stat.permissions()) << '\n';
}
