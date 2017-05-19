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
            char* cmd = new char[5];
            unsigned int val;
            unsigned char cval;
            sscanf(cline, "%s %u", cmd, &val);
            ret.push_back(1);
            cval = val;
            ret.push_back(cval);
            std::cout << "encountered instruction \"" << cmd <<"\" with opcode \"1\"." << std::endl;
            delete cmd;
        }
        else if (stringStartsWith(line, "add"))
        {
            ret.push_back(4);
        }
        else if (stringStartsWith(line, "prnt"))
        {
            ret.push_back(13);
        }
        else if (stringStartsWith(line, "exit"))
        {
            ret.push_back(12);
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