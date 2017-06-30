#include <blu/core/CPU.hpp>
#include <blu/parser/Assembler.hpp>
#include <blu/parser/TokenChecker.hpp>
#include <blu/parser/Tokenizer.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <regex>
/*
int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        std::cout << "Usage: blu %filename%" << std::endl;
        return 0;
    }
    std::string filename = argv[1];
    blu::Assembler as;
    int buf_size = 0;
    unsigned char* buf = as.assemble(filename, buf_size);
    blu::CPU cpu;
    cpu.execInstructionBuffer(buf, buf_size);
    std::string s;
    std::cin >> s;
    return 0;
}*/

int main(int argc, char** argv)
{
    /*if (argc <= 1)
    {
        std::cout << "Usage: blu %filename%" << std::endl;
        return 0;
    }
     */
    std::string filename = "test.blu";

    std::ifstream t(filename);
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());


    blu::Tokenizer tz;
    tz.registerChecker(new blu::WhitespaceChecker());
    tz.registerChecker(new blu::NumberChecker());
    tz.registerChecker(new blu::WordChecker());
    tz.registerChecker(new blu::SymbolChecker());

    std::function<void(blu::Token&)> keyword_checker = [] (blu::Token &tok)
    {
        if (tok.Type == "WORD")
        {
            if (tok.Content == "bool" || tok.Content == "int" || tok.Content == "float" || tok.Content == "void")
            {
                tok.Type = "KEYWORD";
            }
            if (tok.Content == "if" || tok.Content == "else" || tok.Content == "while")
            {
                tok.Type = "KEYWORD";
            }
            if(tok.Content == "return")
            {
                tok.Type = "KEYWORD";
            }
        }
    };

    tz.registerPostChecker(keyword_checker);
    std::vector<blu::Token> tokens = tz.tokenize(str);

    for (auto tok : tokens)
    {
        if (tok.Type == "WHITESPACE")
        {
            std::cout << "WHITESPACE --- COUNT: " << tok.Content.size() << std::endl;
            continue;
        }
        std::cout << tok.Type << " --- " << tok.Content << std::endl;
    }
    std::string s;
    std::cin >> s;
}

