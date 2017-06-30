#ifndef BLU_TOKENCHECKER_HPP
#define BLU_TOKENCHECKER_HPP

#include <unordered_map>
#include <string>

namespace blu
{
    class TokenChecker
    {
    public:
        TokenChecker();

        std::string getType()
        {
            return mType;
        }
        virtual bool contains(char _c) = 0;
        virtual bool startsWith(char _c) = 0;
    protected:
        std::string mType;
    };

    class WhitespaceChecker : public TokenChecker
    {
    public:
        WhitespaceChecker();
        virtual bool contains(char _c);
        virtual bool startsWith(char _c);
    };

    class SymbolChecker : public TokenChecker
    {
    public:
        SymbolChecker();
        virtual bool contains(char _c);
        virtual bool startsWith(char _c);
    };

    class WordChecker : public TokenChecker
    {
    public:
        WordChecker();
        virtual bool contains(char _c);
        virtual bool startsWith(char _c);
    };

    class NumberChecker : public TokenChecker
    {
    public:
        NumberChecker();
        virtual bool contains(char _c);
        virtual bool startsWith(char _c);
    };
}

#endif