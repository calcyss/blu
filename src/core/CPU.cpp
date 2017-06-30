#include <blu/core/CPU.hpp>

#include <iostream>

#include <blu/core/Instruction.hpp>
#include <blu/core/Stack.hpp>
#include <blu/core/InstructionBuffer.hpp>
#include <blu/core/StackFrame.hpp>

using namespace blu;

CPU::CPU(int _stackSize)
{

    mRunning = false;
    mStack = new Stack();
    //Fill instruction set
    mInstructionSet[is::nop] = new blu::nop(this);

    mInstructionSet[is::push] = new blu::push(this);
    mInstructionSet[is::pop] = new blu::pop(this);
    mInstructionSet[is::popn] = new blu::popn(this);

    mInstructionSet[is::add] = new blu::add(this);
    mInstructionSet[is::sub] = new blu::sub(this);
    mInstructionSet[is::mul] = new blu::mul(this);
    mInstructionSet[is::div] = new blu::div(this);

    mInstructionSet[is::jmp] = new blu::jmp(this);
    mInstructionSet[is::call] = new blu::call(this);
    mInstructionSet[is::ret] = new blu::ret(this);

    mInstructionSet[is::halt] = new blu::halt(this);
    mInstructionSet[is::exit] = new blu::exit(this);

    mInstructionSet[is::prnt] = new blu::prnt(this);
    //
}
CPU::~CPU()
{
    for (auto pair : mInstructionSet)
    {
        delete pair.second;
    }
}

void CPU::execInstructionBuffer(InstructionBuffer& _buffer)
{
    StackFrame* sf = new StackFrame();
    sf->Buffer = &_buffer;
    sf->ReturnAddress = 0;

    mStackFrames.push(sf);

    mRunning = true;

    StackFrame* current = mStackFrames.top();

    while (mRunning)
    {
        unsigned char opcode = current->Buffer[current->Buffer->getIP()];
    }
}

Stack* CPU::getCurrentStack()
{
    return mStacks.top();
}

bool& CPU::getRunning()
{
    return mRunning;
}