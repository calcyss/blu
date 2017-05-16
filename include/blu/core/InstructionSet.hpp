#ifndef BLU_INSTRUCTION_HPP
#define BLU_INSTRUCTION_HPP

namespace blu
{
    class CPU;

    class InstructionBuffer
    {

    };

    class InstructionSet
    {
    public:
        friend class CPU;

        static void nop(CPU* _cpu);
        static void exit(CPU* _cpu);

        static void add(CPU* _cpu);
        static void sub(CPU* _cpu);
        static void mul(CPU* _cpu);
        static void div(CPU* _cpu);

        static void fadd(CPU* _cpu);
        static void fsub(CPU* _cpu);
        static void fmul(CPU* _cpu);
        static void fdiv(CPU* _cpu);

        static void push(CPU* _cpu);
        static void pop(CPU* _cpu);
        static void sto(CPU* _cpu);
        static void fsto(CPU* _cpu);
        static void ssto(CPU* _cpu);

        static void jmp(CPU* _cpu);

        static void prnt(CPU* _cpu);
        static void syscall(CPU* _cpu);
    };
}

#endif