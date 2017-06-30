#include <blu/core/Stack.hpp>

using namespace blu;

Stack::Stack(int _size)
{
    mData = new unsigned char[_size];
    mSize = _size;
}
Stack::~Stack()
{
    delete[] mData;
}

void Stack::push(unsigned char _data)
{
    mData[mSP] = _data;
    mSP++;
}
void Stack::push(unsigned char* _data, int _n)
{
    for (int i = 0; i < _n; i++)
    {

    }
}
unsigned char Stack::pop()
{
    unsigned char ret = mData[mSP - 1];
    mSP--;
    return ret;
}
unsigned char* Stack::pop(int _n)
{
    unsigned char* ret = new unsigned char[_n];

    for (int i = 0; i < _n; i++)
    {
        int index = (mSP - _n) + i;
        ret[i] = mData[index];
    }

    mSP -= _n;
    return ret;
}

bool Stack::popb()
{
    bool ret = (bool)mData[mSP - 1];
    mSP--;
    return ret;
}
int Stack::popi()
{
    int ret;
    unsigned char* retb = (unsigned char*)&ret;
    for (int i = 0; i < 4; i++)
    {
        int index = (mSP - 5) + i;
        retb[i] = mData[index];
    }
    mSP -= 4;
    return ret;
}
float Stack::popf()
{
    float ret;
    unsigned char* retb = (unsigned char*)&ret;
    for (int i = 0; i < 4; i++)
    {
        int index = (mSP - 5) + i;
        retb[i] = mData[index];
    }
    mSP -= 4;
    return ret;
}