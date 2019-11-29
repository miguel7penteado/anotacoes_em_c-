//#define XERR
#include "compactor.ih"

void Compactor::run()
{
    bool replace = Arg::instance().option('r');

    Files files;

    while (files)
    {
        string fname{ files.next() };
        cout << "processing " << fname << '\n';

        Parser parser(fname);
        if (parser.parse() != 0)
            throw Exception{} << "Error(s) while processing " << fname;

        if (replace)
            filesystem::rename(fname + ".vb", fname);
    }
}
