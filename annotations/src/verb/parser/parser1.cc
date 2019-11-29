#include "parser.ih"

Parser::Parser(string const &fname)
:
    d_in( Exception::factory<ifstream>(fname) ),
    d_out(Exception::factory<ofstream>(fname + ".vb") ),
    d_scanner(d_in)
{}

