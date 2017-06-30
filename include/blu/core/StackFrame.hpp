#ifndef BLU_STACKFRAME_HPP
#define BLU_STACKFRAME_HPP

#include <unordered_map>
#include <string>

namespace blu
{
    class InstructionBuffer;
    class Variable;

    class StackFrame
    {
    public:
        int ReturnAddress;
        std::unordered_map<std::string, blu::Variable*> Variables;
        InstructionBuffer* Buffer;
    };
}

#endif