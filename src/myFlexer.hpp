#ifndef MYFLEXLEXER_H
#define MYFLEXLEXER_H

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

class myFlexer : public yyFlexLexer {
public:
    
    myFlexer(std::istream* in) : yyFlexLexer(in) {};
     virtual ~myFlexer() = default;
    virtual int yylex() ;
};

#endif