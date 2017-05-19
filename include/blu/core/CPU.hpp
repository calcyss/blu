#ifndef BLU_CPU_HPP
#define BLU_CPU_HPP

#include <unordered_map>

namespace blu
{
    class Instruction;

    class CPU
    {
    public:
        CPU(int _stackSize = 1024);
        ~CPU();
        void execInstructionBuffer(unsigned char* _buffer, int _size);

        unsigned char* getStack(int &_size);
        unsigned char* getInstructionBuffer(int &_size);
        int& getSP();
        int& getIP();
        bool& getRunning();
    private:
        unsigned char *mStack, *mBuffer;
        int mStackSize, mBufferSize, mSP, mIP;
        bool mRunning;

        std::unordered_map<int, Instruction*> mInstructionSet;
    };
}

#endif