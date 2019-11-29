#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

int main()
{
    cout << fs::exists("fs.cc") << '\n';

    fs::file_status stat = fs::status("fs.cc");
    cout << exists(stat) << '\n';
    cout << (stat.type() != fs::file_type::not_found) << '\n';

    cout << oct;

    fs::perms required = fs::perms::owner_read | fs::perms::owner_write;

    cout << ((stat.permissions() & required) == required) << '\n';

    cout << static_cast<size_t>(stat.permissions()) << '\n';

    error_code ec;
    fs::rename("fs.cc", "fs2.cc", ec);
    cout << ec << '\n';

    fs::rename("fs2.cc", "fs.cc", ec);
    cout << ec << '\n';

}
