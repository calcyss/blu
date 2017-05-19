#ifndef BLU_INSTRUCTION_HPP
#define BLU_INSTRUCTION_HPP

#include <functional>

namespace blu
{
    class CPU;

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
        friend class CPU;
        nop(CPU* _cpu);
        virtual ~nop();

        virtual void operator()();
    };

    class push : public Instruction
    {
    public:
        friend class CPU;
        push(CPU* _cpu);
        virtual ~push();

        virtual void operator()();
    };

    class pop : public Instruction
    {
    public:
        friend class CPU;
        pop(CPU* _cpu);
        virtual ~pop();

        virtual void operator()();
    };

    class popn : public Instruction
    {
    public:
        friend class CPU;
        popn(CPU* _cpu);
        virtual ~popn();

        virtual void operator()();
    };

    class add : public Instruction
    {
    public:
        friend class CPU;
        add(CPU* _cpu);
        virtual ~add();

        virtual void operator()();
    };

    class sub : public Instruction
    {
    public:
        friend class CPU;
        sub(CPU* _cpu);
        virtual ~sub();

        virtual void operator()();
    };

    class mul : public Instruction
    {
    public:
        friend class CPU;
        mul(CPU* _cpu);
        virtual ~mul();

        virtual void operator()();
    };

    class div : public Instruction
    {
    public:
        friend class CPU;
        div(CPU* _cpu);
        virtual ~div();

        virtual void operator()();
    };

    class jmp : public Instruction
    {
    public:
        friend class CPU;
        jmp(CPU* _cpu);
        virtual ~jmp();

        virtual void operator()();
    };

    class call : public Instruction
    {
    public:
        friend class CPU;
        call(CPU* _cpu);
        virtual ~call();

        virtual void operator()();
    };

    class ret : public Instruction
    {
    public:
        friend class CPU;
        ret(CPU* _cpu);
        virtual ~ret();

        virtual void operator()();
    };

    class halt : public Instruction
    {
    public:
        friend class CPU;
        halt(CPU* _cpu);
        virtual ~halt();

        virtual void operator()();
    };

    class exit : public Instruction
    {
    public:
        friend class CPU;
        exit(CPU* _cpu);
        virtual ~exit();

        virtual void operator()();
    };

    class prnt : public Instruction
    {
    public:
        friend class CPU;
        prnt(CPU* _cpu);
        virtual ~prnt();

        virtual void operator()();
    };
}

#endif