#include <blu/core/Instruction.hpp>

#include <iostream>

#include <blu/core/CPU.hpp>

using namespace blu;

Instruction::Instruction(CPU *_cpu)
{
    mCPU = _cpu;
    Size = 1;
}
Instruction::~Instruction()
{

}

nop::nop(CPU* _cpu) : Instruction(_cpu)
{
    Code = 0;
}
void nop::operator()()
{
    //Do nothing, lmao
}

push::push(CPU* _cpu) : Instruction(_cpu)
{
    Size = 2;
    Code = 1;
}
void push::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val = buffer[IP + 1];
    mStack[SP] = val;
    SP++;

}

pop::pop(CPU* _cpu) : Instruction(_cpu)
{
    Code = 2;
}
void pop::operator()()
{
    mCPU->mSP--;
}

popn::popn(CPU* _cpu) : Instruction(_cpu)
{
    Size = 2;
    Code = 3;
}
void popn::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val = buffer[IP + 1];
    SP -= val;
}

add::add(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
    Code = 4;
}
void add::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 + val2;
    stack[SP] = ret;
    SP++;
}

sub::sub(CPU* _cpu) : Instruction(_cpu)
{

}
void sub::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 - val2;
    stack[SP] = ret;
    SP++;
}

mul::mul(CPU* _cpu) : Instruction(_cpu)
{

}
void mul::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 + val2;
    stack[SP] = ret;
    SP++;
}

div::div(CPU* _cpu) : Instruction(_cpu)
{

}
void div::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 + val2;
    stack[SP] = ret;
    SP++;
}

jmp::jmp(CPU* _cpu) : Instruction(_cpu)
{

}
void jmp::operator()()
{

}

call::call(CPU* _cpu) : Instruction(_cpu)
{

}
void call::operator()()
{

}

ret::ret(CPU* _cpu) : Instruction(_cpu)
{

}
void ret::operator()()
{

}

halt::halt(CPU* _cpu) : Instruction(_cpu)
{

}
void halt::operator()()
{

}

exit::exit(CPU* _cpu) : Instruction(_cpu)
{

}
void exit::operator()()
{
    mCPU->mRunning = false;
}

prnt::prnt(CPU* _cpu) : Instruction(_cpu)
{
    Code = 13;
    Size = 1;
}
void prnt::operator()()
{
    int &IP = mCPU->mIP;
    int &SP = mCPU->mSP;
    unsigned char *buffer = mCPU->mBuffer;
    unsigned char *stack = mCPU->mStack;

    std::cout << "Value at stack address " << SP - 1 << ": " << stack[SP - 1] << "." << std::endl;
}