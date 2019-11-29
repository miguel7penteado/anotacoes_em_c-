#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace filesystem;

//code
void breadth(path const &dir)           // starting dir.
{
    vector<path> level{ dir };          // currently processed level

    while (not level.empty())           // process all its dirs.
    {
        vector<path> next;              // dirs of the next level

        for (auto const &dir: level)    // visit all dirs at this level
        {
            cout << "At " << dir << '\n';
                                        // at each dir: visit all entries
            for (auto const &entry: directory_iterator{ dir })
            {
                if (entry.is_directory())   // store all dirs at the current
                    next.push_back(entry);  //  level
                else                        // or process its non-dir entry
                    cout << "   entry: " << entry << '\n';
            }
        }

        level = next;                   // continue at the next level,
    }                                   // which eventually won't exist
}
//=

int main()
{
    breadth("/home/frank/tmp");
}
