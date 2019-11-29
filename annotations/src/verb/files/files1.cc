//#define XERR
#include "files.ih"

Files::Files()
{
    string arg0{ Arg::instance()[0] };

    size_t pos = arg0.find(':');                // ':' in 1st arg?

    if (pos == string::npos)                    // no: just a list of names
        fillArgs();                             // add them to d_fname
    else
        read(arg0.substr(pos + 1));             // or read the names fm file
}
