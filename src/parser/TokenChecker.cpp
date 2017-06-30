#include <blu/parser/TokenChecker.hpp>

#include <regex>

using namespace blu;

TokenChecker::TokenChecker()
{
    mType = "DEFAULT";
}

SymbolChecker::SymbolChecker()
{
    mType = "SYMBOL";
}
bool SymbolChecker::contains(char _c)
{
    std::regex pattern("[+\\-*/,.:;#'\"(){}]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}
bool SymbolChecker::startsWith(char _c)
{
    std::regex pattern("[+\\-*/,.:;#'\"(){}]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}

WhitespaceChecker::WhitespaceChecker()
{
    mType = "WHITESPACE";
}
bool WhitespaceChecker::contains(char _c)
{
    std::regex pattern("[\\s]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}
bool WhitespaceChecker::startsWith(char _c)
{
    std::regex pattern("[\\s]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}

WordChecker::WordChecker()
{
    mType = "WORD";
}
bool WordChecker::contains(char _c)
{
    std::regex pattern("[a-zA-Z0-9_]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}
bool WordChecker::startsWith(char _c)
{
    std::regex pattern("[a-zA-Z_]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}

NumberChecker::NumberChecker()
{
    mType = "NUMBER";
}
bool NumberChecker::contains(char _c)
{
    std::regex pattern("[0-9]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}
bool NumberChecker::startsWith(char _c)
{
    std::regex pattern("[0-9]+");
    std::string input;
    input += _c;
    return std::regex_match(input, pattern);
}

