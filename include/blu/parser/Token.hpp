#ifndef BLU_TOKEN_HPP
#define BLU_TOKEN_HPP

#include <string>

namespace blu
{
    class Token
    {
    public:
        std::string Type = "DEFAULT";
        std::string Content = "";
    };
}

#endif