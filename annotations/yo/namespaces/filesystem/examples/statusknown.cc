#include <iostream>
#include <unordered_map>
#include <filesystem>

using namespace std;
using namespace filesystem;

//demo
namespace
{
    std::unordered_map<file_type, char const *> statusMap =
    {
        { file_type::not_found, "an unknown file" },
        { file_type::none,      "not yet or erroneously evaluated "
                                                            "file type" },
        { file_type::regular,   "a regular file" },
        { file_type::directory, "a directory" },
        { file_type::symlink,   "a symbolic link" },
        { file_type::block,     "a block device" },
        { file_type::character, "a character device" },
        { file_type::fifo,      "a named pipe" },
        { file_type::socket,    "a socket file" },
        { file_type::unknown,   "an unknown file type" }
    };
}

int main()
{
    cout << oct;

    string line;
    while (true)
    {
        cout << "enter the name of a file system entry: ";
        if (not getline(cin, line) or line.empty())
            break;

        path entry{ line };

        error_code ec;
        file_status stat = status(entry, ec);

        if (not status_known(stat))
        {
            cout << "status of " << entry << " is unknown. "
                                            "Ec = " << ec << '\n';
            continue;
        }

        cout << "status of " << entry << ": type = " <<
                 statusMap[stat.type()] <<
                 ", permissions: " <<
                    static_cast<size_t>(stat.permissions()) << '\n';
    }
}
//=
