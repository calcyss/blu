#ifndef BLU_TOKENIZER_HPP
#define BLU_TOKENIZER_HPP

#include <vector>
#include <string>
#include <functional>
#include <blu/parser/Token.hpp>

namespace blu
{
    class TokenChecker;

    class Tokenizer
    {
    public:
        Tokenizer();
        ~Tokenizer();

        void registerChecker(TokenChecker* _checker);
        void registerPostChecker(std::function<void(blu::Token&)> _checker);

        std::vector<Token> tokenize(std::string _data);
    private:
        std::vector<TokenChecker*> mCheckers;
        std::vector<std::function<void(blu::Token&)>> mPostCheckers;

        std::string swallowWhile(TokenChecker* _checker, std::string _data, int &_position);
    };
}

#endif