//#define XERR
#include "files.ih"

void Files::read(string const &fname)
{
    ifstream in{ Exception::factory<ifstream>(fname) };
    string line;

    while (getline(in, line))
    {
        size_t pos = line.find_first_not_of(" \t");
        if (pos == string::npos or line[pos] == '#')    // empty or comment?
            continue;                                   // then skip this line

        d_fname.push_back(String::trim(line));
    }
}
