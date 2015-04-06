#include "Soundex.h"

std::string Soundex::encode(const std::string& word) const
{
    return zeroPad(head(word) + encodedDigits(word));
}

std::string Soundex::head(const std::string& word) const
{
    return word.substr(0, 1);
}

std::string Soundex::encodedDigits(const std::string& word) const
{
    if (word.length() > 1)
        return encodedDigit();
    return "";
}

std::string Soundex::encodedDigit() const
{
    return "1";
}

static const size_t MaxCodeLength = 4;
std::string Soundex::zeroPad(const std::string& word) const
{
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + std::string(zerosNeeded, '0');
}
