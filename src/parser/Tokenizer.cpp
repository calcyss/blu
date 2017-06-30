#include <blu/parser/Tokenizer.hpp>

using namespace blu;

#include <blu/parser/TokenChecker.hpp>

#include <iostream>

Tokenizer::Tokenizer()
{

}
Tokenizer::~Tokenizer()
{
    for (auto checker : mCheckers)
    {
        delete checker;
    }
}

std::vector<Token> Tokenizer::tokenize(std::string _data)
{
    int position = 0;
    std::vector<Token> ret;

    while (position < _data.size())
    {
        for (auto checker : mCheckers)
        {
            std::cout << "Position/Size: " << position << "/" << _data.size() << std::endl;
            if (checker->startsWith(_data[position]))
            {
                std::cout << "Matching token: " << checker->getType() << std::endl;
                std::string data = swallowWhile(checker, _data, position);
                Token t;
                t.Type = checker->getType();
                t.Content = data;
                for (auto checker : mPostCheckers)
                {
                    checker(t);
                }
                ret.push_back(t);
            }
        }
    }

    return ret;
}

void Tokenizer::registerChecker(TokenChecker *_checker)
{
    mCheckers.push_back(_checker);
}

void Tokenizer::registerPostChecker(std::function<void(blu::Token&)> _checker)
{
    mPostCheckers.push_back(_checker);
}

std::string Tokenizer::swallowWhile(TokenChecker *_checker, std::string _data, int &_position)
{
    std::string ret;
    while (_position < _data.size())
    {
        if (_checker->contains(_data[_position]))
        {
            ret += _data[_position];
            _position++;
        }
        else break;
    }
    return ret;
}