#ifndef BLU_ASSEMBLER_HPP
#define BLU_ASSEMBLER_HPP

#include <string>

namespace blu
{
    class Assembler
    {
    public:
        Assembler();
        ~Assembler();

        unsigned char* assemble(std::string _filename, int &_size);
    private:
        bool stringStartsWith(std::string _string, std::string _prefix);
    };
}

#endif