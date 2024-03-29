// Generated by Bisonc++ V6.03.00 on Fri, 08 Nov 2019 10:01:15 +0530

#ifndef Parser_h_included
#define Parser_h_included

#include <fstream>
#include <string>

#include "parserbase.h"

#include "../scanner/scanner.h"


#undef Parser
    // CAVEAT: between the baseclass-include directive and the 
    // #undef directive in the previous line references to Parser 
    // are read as ParserBase.
    // If you need to include additional headers in this file 
    // you should do so after these comment-lines.


class Parser: public ParserBase
{
    enum VerbContext
    {
        NO,
        BEGIN,
        END
    };

    VerbContext   d_verbContext = NO;
    std::string   d_blanks;

    std::ifstream d_in;
    std::ofstream d_out;
    
    // $insert scannerobject
    Scanner d_scanner;
        
    public:
        Parser(std::string const &fname);
        int parse();

    private:
        void outBlanks();               // collected blanks to d_out
        void out();                     // d_scanner.matched() to d_out 
        void blankOut();                // outBlanks + out
                                          
        void error();                   // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc
        void exceptionHandler(std::exception const &exc);

    // support functions for parse():
        void executeAction_(int ruleNr);
        void errorRecovery_();
        void nextCycle_();
        void nextToken_();
        void print_();
};


#endif

