#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex
{
public:
    std::string encode(const std::string& word) const;

    std::string encodedDigit(char letter) const;

private:
    std::string head(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
    bool isComplete(const std::string& encoding) const;
    std::string lastDigit(const std::string& encoding) const;
    std::string zeroPad(const std::string& word) const;
};

#endif // SOUNDEX_H
