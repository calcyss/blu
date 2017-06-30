#include <blu/core/InstructionBuffer.hpp>

using namespace blu;

InstructionBuffer::InstructionBuffer(int _reserveSize)
{
    mBuffer.reserve(_reserveSize);
}
InstructionBuffer::~InstructionBuffer()
{

}

int InstructionBuffer::getIP()
{
    return mIP;
}
int InstructionBuffer::getSize()
{
    return mBuffer.size();
}
void InstructionBuffer::setIP(int _val)
{
    mIP = _val;
}
void InstructionBuffer::incrIP(int _val)
{
    mIP += _val;
}
void InstructionBuffer::decrIP(int _val)
{
    mIP -= _val;
}
unsigned char InstructionBuffer::operator[](int _index)
{
    return mBuffer[_index];
}

void InstructionBuffer::push(unsigned char _val)
{
    mBuffer.push_back(_val);
}
void InstructionBuffer::push(int _val)
{
    unsigned char* val = (unsigned char*)&_val;
    for(int i = 0; i < 4; i++)
    {
        mBuffer.push_back(val[i]);
    }
}
void InstructionBuffer::push(bool _val)
{
    unsigned char val = (unsigned char)_val;
    mBuffer.push_back(val);
}
void InstructionBuffer::push(float _val)
{
    unsigned char* val = (unsigned char*)&_val;
    for(int i = 0; i < 4; i++)
    {
        mBuffer.push_back(val[i]);
    }
}