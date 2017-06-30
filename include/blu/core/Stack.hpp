#ifndef BLU_STACK_HPP
#define BLU_STACK_HPP

namespace blu
{
    class Stack
    {
    public:
        Stack(int _size = 1048576);
        ~Stack();

        void push(unsigned char _data);
        void push(unsigned char* _data, int _n);
        unsigned char pop();
        bool popb();
        int popi();
        float popf();
        unsigned char* pop(int _n);
    private:
        unsigned char* mData;
        int mSize;
        int mSP;
    };
}

#endif