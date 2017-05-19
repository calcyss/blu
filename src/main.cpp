#include <blu/core/CPU.hpp>
#include <blu/core/Assembler.hpp>

#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    blu::Assembler as;
    int buf_size = 0;
    unsigned char* buf = as.assemble("test.asm", buf_size);
    blu::CPU cpu;
    cpu.execInstructionBuffer(buf, buf_size);
    std::string s;
    std::cin >> s;
    return 0;
}