#include "CharUtil.h"

#include <cctype>
#include <string>

namespace charutil
{

char lower(char c)
{
    return std::tolower(static_cast<unsigned char>(c));
}

char upper(char c)
{
    return std::toupper(static_cast<unsigned char>(c));
}

bool isVowel(char letter)
{
    return std::string("aeiouy").find(charutil::lower(letter)) != std::string::npos;
}

}
