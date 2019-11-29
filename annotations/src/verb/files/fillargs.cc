//#define XERR
#include "files.ih"

void Files::fillArgs()
{
    Arg const &arg = Arg::instance();

    for (size_t idx = 0, end = arg.nArgs(); idx != end; ++idx)
        d_fname.push_back(arg[idx]);
}
