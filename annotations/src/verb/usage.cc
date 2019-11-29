//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [options] file(s)
Where:
    [options] - optional arguments (short options between parentheses):
        --help (-h)         - provide this help
        --version (-v)      - show version information and terminate
        --replace (-r)      - replace .yo files by generated '.yo.vb' files.

    file(s) - names of files where verb(...) macros must be compacted. 
              Processed files receive extra .vb extensions.
              Use file:filename (no blanks) as single argument if the files to
              process are read from lines in 'filename' (empty lines, lines
              starting with # are ignored)

)_";

}

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << info;
}


