#ifndef BLU_VARIABLE_HPP
#define BLU_VARIABLE_HPP

#include <string>

#include "Statement.hpp"

namespace blu
{
    class VariableDecl : public Statement
    {
    public:
        VariableDecl(std::string _name);
    private:
        std::string mName;
    };

    class VariableDeclAssign : public Statement
    {
    public:
        VariableDeclAssign(std::string _name);
    private:
        std::string mName;
    };

    class VariableAssign : public Statement
    {
    public:
        VariableAssign(std::string _name);
    private:
        std::string mName;
    };
}

#endif