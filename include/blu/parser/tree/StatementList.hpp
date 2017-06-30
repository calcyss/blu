#ifndef BLU_STATEMENTLIST_HPP
#define BLU_STATEMENTLIST_HPP

#include <vector>

#include "Statement.hpp"

namespace blu
{
    class StatementList : public Statement
    {
    public:
        void addStatement(Statement* _stm);
    private:
        std::vector<Statement*> mStatements;
    };
}

#endif