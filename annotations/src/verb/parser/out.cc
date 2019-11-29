#include "parser.ih"

void Parser::out()
{
    d_out << d_scanner.matched();
}


