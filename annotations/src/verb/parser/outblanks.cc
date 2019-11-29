#include "parser.ih"

void Parser::outBlanks()
{
    if (d_blanks.empty())
        return;

    d_out << d_blanks;
    d_blanks.clear();
}
