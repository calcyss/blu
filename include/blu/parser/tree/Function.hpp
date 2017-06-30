#ifndef BLU_FUNCTION_HPP
#define BLU_FUNCTION_HPP

#include "Statement.hpp"

#include <string>
#include <vector>

namespace blu
{
    class StatementList;

    class Function : public Statement
    {
    public:
        Function();
        ~Function();
        void addArgument(std::string _arg);
        void addStatement(Statement* _stmt);
    private:
        std::string mName;
        std::vector<std::string> mArguments;
        StatementList* mStatementList;
    };
}

#endif