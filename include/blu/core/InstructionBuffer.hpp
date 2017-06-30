#ifndef BLU_INSTRUCTIONBUFFER_HPP
#define BLU_INSTRUCTIONBUFFER_HPP

#include <vector>

namespace blu
{
    class InstructionBuffer
    {
    public:
        InstructionBuffer(int _reserveSize = 2048);
        ~InstructionBuffer();

        int getIP();
        int getSize();
        void setIP(int _val);
        void incrIP(int _val);
        void decrIP(int _val);

        void push(unsigned char _val);
        void push(int _val);
        void push(bool _val);
        void push(float _val);

        unsigned char
    private:
        int mIP;
        std::vector<unsigned char> mBuffer;
    };
}

#endif