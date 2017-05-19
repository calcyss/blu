#include <blu/core/Assembler.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace blu;

Assembler::Assembler()
{

}
Assembler::~Assembler()
{

}

unsigned char* Assembler::assemble(std::string _filename, int &_size)
{
    std::vector<unsigned char> ret;

    std::ifstream file(_filename);

    std::string line;
    while (std::getline(file, line))
    {
        if (stringStartsWith(line, "push"))
        {
            const char* cline = line.c_str();
            char* cmd;
            unsigned char val;
            sscanf(cline, "%s %u", cmd, &val);
            ret.push(1);
            ret.push(val);
        }
        else if (stringStartsWith(line, "add"))
        {
            ret.push(4);
        }
        else if (stringStartsWith(line, "prnt"))
        {
            ret.push(13);
        }
        else if (stringStartsWith(line, "exit"))
        {
            ret.push(12);
        }
    }

    file.close();

    _size = ret.size();
    return &ret[0];
}

bool Assembler::stringStartsWith(std::string _string, std::string _prefix)
{
    return _string.substr(0, _prefix.size()) == _prefix;
}