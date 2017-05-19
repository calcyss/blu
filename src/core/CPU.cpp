#include <blu/core/CPU.hpp>

#include <iostream>

#include <blu/core/Instruction.hpp>

using namespace blu;

CPU::CPU(int _stackSize)
{
    mStack = new unsigned char[_stackSize];
    mSP = 0;
    mRunning = false;

    //Fill instruction set
    mInstructionSet[0] = new nop(this);

    mInstructionSet[1] = new push(this);
    mInstructionSet[2] = new pop(this);
    mInstructionSet[3] = new popn(this);

    mInstructionSet[4] = new add(this);
    mInstructionSet[5] = new sub(this);
    mInstructionSet[6] = new mul(this);
    mInstructionSet[7] = new div(this);

    mInstructionSet[8] = new jmp(this);
    mInstructionSet[9] = new call(this);
    mInstructionSet[10] = new ret(this);

    mInstructionSet[11] = new halt(this);
    mInstructionSet[12] = new exit(this);

    mInstructionSet[13] = new prnt(this);
    //
}
CPU::~CPU()
{
    for (auto pair : mInstructionSet)
    {
        delete pair.second;
    }
    delete[] mStack;
}

void CPU::execInstructionBuffer(unsigned char *_buffer, int _size)
{
    mIP = 0;

    mRunning = true;

    mBuffer = _buffer;
    mBufferSize = _size;

    while (mRunning && mIP < mBufferSize)
    {
        unsigned char opcode = mBuffer[mIP];
        std::cout << "Executing opcode \"" << (unsigned int)opcode << "\"" << std::endl;
        Instruction* instr = mInstructionSet[opcode];
        if (instr == 0)
        {
            std::cerr << "Unknown opcode \"" << (unsigned int)opcode << "\" ! Skipping." << std::endl;
            continue;
        }
        (*instr)();
        mIP += instr->Size;
    }
}

unsigned char* CPU::getStack(int &_size)
{
    _size = mStackSize;
    return mStack;
}
unsigned char* CPU::getInstructionBuffer(int &_size)
{
    _size = mBufferSize;
    return mBuffer;
}
int& CPU::getSP()
{
    return mSP;
}
int& CPU::getIP()
{
    return mIP;
}
bool& CPU::getRunning()
{
    return mRunning;
}