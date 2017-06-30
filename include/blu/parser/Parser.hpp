#ifndef BLU_PARSER_HPP
#define BLU_PARSER_HPP

#include <vector>

namespace blu
{
    class Token;

    //AST Node classes
    class StatementList;
    class Function;
    class VariableDecl;
    class VariableDeclAssign;
    class VariableAssign;
    //

    class Parser
    {
    public:
        Parser(std::vector<Token> _tokens);
        ~Parser();

        StatementList* parse();
        Function* parseFunction();
        VariableDecl* parseVariableDecl();
        VariableDeclAssign* parseVariableDeclAssign();
        VariableAssign* parseVariableAssign();

    private:
        int mPosition;
        std::vector<Token> mTokens;

        std::vector<Token> swallowWhitespaces();
        Token peek();
        Token peek(int i);
        Token peekIW(int i);
        Token swallow();
        std::vector<Token> swallow(int i);
        std::vector<Token> swallowIW(int i);
    };
}

#endif