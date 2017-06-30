#include <blu/parser/Parser.hpp>

#include <blu/parser/tree/StatementList.hpp>
#include <blu/parser/Token.hpp>
#include <blu/parser/tree/Function.hpp>
#include <blu/parser/tree/Variable.hpp>

#include <asmjit/asmjit.h>

using namespace blu;

Parser::Parser(std::vector<Token> _tokens)
{
    mTokens = _tokens;
    mPosition = 0;
}
Parser::~Parser()
{

}

StatementList* Parser::parse()
{
    StatementList* statements = new StatementList();
    swallowWhitespaces();
    Token curr = peek();
    while (mPosition < mTokens.size())
    {
        if(curr.Type == "KEYWORD")
        {
            if(curr.Content == "function")
            {
                statements->addStatement(parseFunction());
            }
            else if(curr.Content == "var")
            {
                if(peekIW(2).Type == "SYMBOL")
                {
                    if(peekIW(2).Content == "=")
                    {

                    }
                    if(peekIW(2).Content == ";")
                    {
                        
                    }
                }
            }
        }
        else  if(curr.Type == "WORD")
        {
            Token next = peekIW(1);

            if(next.Type == "SYMBOL")
            {
                if(next.Content == "=")
                {
                    VariableAssign* va = parseVariableAssign();
                }
            }
        }
    }
}

Function* Parser::parseFunction()
{
    swallow();
    swallowWhitespaces();
    Token function_name_tok = swallow();

}

Variable* Parser::parseVariable()
{

}

std::vector<Token> Parser::swallowWhitespaces()
{
    std::vector<Token> ret;
    Token curr = mTokens[mPosition];
    while (curr.Type == "WHITESPACE")
    {
        ret.push_back(curr);
        mPosition++;
        curr = mTokens[mPosition];
    }
}

Token Parser::peek()
{
    return mTokens[mPosition];
}

Token Parser::peek(int i)
{
    return mTokens[mPosition + i];
}

Token Parser::peekIW(int i)
{
    int index = mPosition;
    Token ret;
    while (i > 0)
    {
        Token t = mTokens[index];
        if(t.Type == "WHITESPACE")
        {
            index++;
        }
        else
        {
            ret = t;
            index++;
            i--;
        }
    }
}

Token Parser::swallow()
{
    return mTokens[mPosition++];
}

std::vector<Token> Parser::swallow(int i)
{
    std::vector<Token> ret;
    int index = mPosition;
    while(index < mPosition + i)
    {
        ret.push_back(mTokens[index]);
        index++;
    }
    mPosition = index;
    return ret;
}

std::vector<Token> Parser::swallowIW(int i)
{
    std::vector<Token> ret;
    int index = mPosition;
    while (i > 0)
    {
        Token t = mTokens[index];
        if(t.Type == "WHITESPACE")
        {
            index++;
        }
        else
        {
            index++;
            i--;
            ret.push_back(t);
        }
    }
    return ret;
}
