#include "parser.ih"

int Parser::lex()
{
    int token;

    while (true)
    {
        token = d_scanner.lex();

        if (token != WS)
            break;

        d_blanks += d_scanner.matched();
    }

    switch (d_verbContext)
    {
        case BEGIN:
            if (size_t pos = d_blanks.find_last_of('\n'); pos != string::npos)
                d_blanks.erase(0, pos + 1); 
            d_verbContext = NO;
        break;

        case END:
            d_blanks = '\n';
            d_verbContext = NO;
        break;

        default:
        break;
    }

    return token;
}

