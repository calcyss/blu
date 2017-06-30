#ifndef BLU_INSTRUCTION_HPP
#define BLU_INSTRUCTION_HPP

#include <functional>

namespace blu
{
    class CPU;

    namespace is
    {
        enum InstructionSet
        {
            nop = 0,

            push,
            pushn,
            pop,
            popn,

            add,
            sub,
            mul,
            div,

            jmp,
            call,
            ret,

            halt,
            exit,

            prnt
        };
    }

    class Instruction
    {
    public:
        Instruction(CPU* _cpu);
        virtual ~Instruction();

        virtual void operator()() = 0;

        int Size;
        unsigned char Code;
    protected:
        CPU* mCPU;
    };

    class nop : public Instruction
    {
    public:
        nop(CPU* _cpu);

        virtual void operator()();
    };

    class push : public Instruction
    {
    public:
        push(CPU* _cpu);

        virtual void operator()();
    };

    class pop : public Instruction
    {
    public:
        pop(CPU* _cpu);

        virtual void operator()();
    };

    class popn : public Instruction
    {
    public:
        popn(CPU* _cpu);

        virtual void operator()();
    };

    class add : public Instruction
    {
    public:
        add(CPU* _cpu);

        virtual void operator()();
    };

    class sub : public Instruction
    {
    public:
        sub(CPU* _cpu);

        virtual void operator()();
    };

    class mul : public Instruction
    {
    public:
        mul(CPU* _cpu);

        virtual void operator()();
    };

    class div : public Instruction
    {
    public:
        div(CPU* _cpu);

        virtual void operator()();
    };

    class jmp : public Instruction
    {
    public:
        jmp(CPU* _cpu);

        virtual void operator()();
    };

    class call : public Instruction
    {
    public:
        call(CPU* _cpu);

        virtual void operator()();
    };

    class ret : public Instruction
    {
    public:
        ret(CPU* _cpu);

        virtual void operator()();
    };

    class halt : public Instruction
    {
    public:
        halt(CPU* _cpu);

        virtual void operator()();
    };

    class exit : public Instruction
    {
    public:
        exit(CPU* _cpu);

        virtual void operator()();
    };

    class prnt : public Instruction
    {
    public:
        prnt(CPU* _cpu);

        virtual void operator()();
    };
}

#endif