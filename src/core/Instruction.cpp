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
    Code = is::nop;
}
void nop::operator()()
{
    //Do nothing, lmao
}

push::push(CPU* _cpu) : Instruction(_cpu)
{
    Size = 2;
    Code = is::push;
}
void push::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char* byteval = &buffer[IP + 1];
    int val = *(int*)byteval;

    stack[SP] = val;
    SP++;
     */
}

pop::pop(CPU* _cpu) : Instruction(_cpu)
{
    Code = is::pop;
}
void pop::operator()()
{
    /*
    mCPU->getSP()--;
     */
}

popn::popn(CPU* _cpu) : Instruction(_cpu)
{
    Size = 2;
    Code = is::popn;
}
void popn::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char val = buffer[IP + 1];
    SP -= val;
     */
}

add::add(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
    Code = is::add;
}
void add::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 + val2;
    stack[SP] = ret;
    SP++;
     */
}

sub::sub(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
    Code = is::sub;
}
void sub::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 - val2;
    stack[SP] = ret;
    SP++;
     */
}

mul::mul(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
    Code = is::mul;
}
void mul::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 * val2;
    stack[SP] = ret;
    SP++;
     */
}

div::div(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
    Code = is::div;
}
void div::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    unsigned char val1 = stack[SP - 2];
    unsigned char val2 = stack[SP - 1];

    unsigned char ret = val1 / val2;
    stack[SP] = ret;
    SP++;
     */
}

jmp::jmp(CPU* _cpu) : Instruction(_cpu)
{
    Size = 5;
    Code = is::jmp;
}
void jmp::operator()()
{

}

call::call(CPU* _cpu) : Instruction(_cpu)
{
    Size = 5;
    Code = is::call;
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
    mCPU->getRunning() = false;
}

prnt::prnt(CPU* _cpu) : Instruction(_cpu)
{
    Size = 1;
}
void prnt::operator()()
{
    /*
    int &IP = mCPU->getIP();
    int &SP = mCPU->getSP();
    int buffer_size, stack_size;
    unsigned char *buffer = mCPU->getInstructionBuffer(buffer_size);
    unsigned char *stack = mCPU->getStack(stack_size);

    std::cout << "Value at stack address " << SP - 1 << ": " << (unsigned int)stack[SP - 1] << "." << std::endl;*/
}