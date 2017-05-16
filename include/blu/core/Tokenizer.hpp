#include <vector>
#include <string>
#include <functional>

namespace blu
{
    class TokenChecker
    {
    public:
        TokenChecker(std::string _name)
        {
            Name = _name;
        }
        TokenChecker(TokenChecker& _other)
        {
            Name = _other.Name;
            startsWith = _other.startsWith;
            endsWith = _other.endsWith;
            contains = _other.contains;
        }

        std::function<bool(char)> startsWith = [] (char) -> bool { return false; };
        std::function<bool(char)> endsWith = [] (char) -> bool { return false; };
        std::function<bool(char)> contains = [] (char) -> bool { return false; };

        std::string Name;
    };
    class Token
    {
    public:
        Token(std::string _name, std::string _content)
        {
            Name = _name;
            Content = _content;
        }

        std::string Name;
        std::string Content;
    };
    class Tokenizer
    {
    public:
        Tokenizer();
        virtual ~Tokenizer();

        void registerChecker(TokenChecker& _checker);

        std::vector<Token> tokenize(std::string _token, std::string _data);
    private:
        std::vector<TokenChecker> mCheckers;

        std::string swallowWhile();
    };
}