#ifndef BLU_CPU_HPP
#define BLU_CPU_HPP

#include <unordered_map>
#include <stack>
#include <vector>


namespace blu
{
    class Instruction;
    class InstructionBuffer;
    class Stack;
    class StackFrame;


    class CPU
    {
    public:
        CPU(int _stackSize);
        ~CPU();
        void addFunction(std::string _name, InstructionBuffer* _buffer);
        void execInstructionBuffer(InstructionBuffer& _buffer);

        Stack* getCurrentStack();
        bool& getRunning();
    private:
        bool mRunning;
        Stack* mStack;
        std::stack<blu::StackFrame*> mStackFrames;
        std::unordered_map<std::string, blu::InstructionBuffer*> mFunctions;

        std::unordered_map<unsigned char, blu::Instruction*> mInstructionSet;
    };
}

#endif