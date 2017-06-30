#include <blu/parser/Assembler.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

#include <blu/core/Instruction.hpp>

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
        unsigned char opcode;
        if (stringStartsWith(line, "push"))
        {
            const char* cline = line.c_str();
            char* cmd = new char[5];
            unsigned int val;
            unsigned char cval;
            sscanf(cline, "%s %u", cmd, &val);
            ret.push_back(1);
            cval = val;
            ret.push_back(cval);
            delete cmd;
        }
        else if (stringStartsWith(line, "add"))
        {
            opcode = is::add;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "sub"))
        {
            opcode = is::sub;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "div"))
        {
            opcode = is::div;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "mul"))
        {
            opcode = is::mul;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "pop"))
        {
            opcode = is::pop;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "prnt"))
        {
            opcode = is::prnt;
            ret.push_back(opcode);
        }
        else if (stringStartsWith(line, "exit"))
        {
            opcode = is::exit;
            ret.push_back(opcode);
        }
    }

    file.close();

    unsigned char* ret_buf = new unsigned char[ret.size()];
    for (int i = 0; i < ret.size(); i++)
    {
        ret_buf[i] = ret[i];
    }
    _size = ret.size();

    return ret_buf;
}

bool Assembler::stringStartsWith(std::string _string, std::string _prefix)
{
    std::string cpy = std::string(_string);
    bool ret = cpy.substr(0, _prefix.size()) == _prefix;
    return ret;
}