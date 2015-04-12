#include "Soundex.h"

#include "CharUtil.h"
#include "StringUtil.h"

#include <unordered_map>

static const size_t MaxCodeLength = 4;
static const std::string NotADigit = "*";

std::string Soundex::encode(const std::string& word) const
{
    return stringutil::zeroPad(
                stringutil::upperFront(stringutil::head(word)) + stringutil::tail(encodedDigits(word)),
                MaxCodeLength);
}

std::string Soundex::encodedDigits(const std::string& word) const
{
    std::string encoding;
    encodeHead(encoding, word);
    encodeTail(encoding, word);
    return encoding;
}

void Soundex::encodeHead(std::string& encoding, const std::string& word) const
{
    encoding += encodedDigit(word.front());
}

std::string Soundex::encodedDigit(char letter) const
{
    const std::unordered_map<char, std::string> encodings
    {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"}
    };

    auto it = encodings.find(charutil::lower(letter));
    return it == encodings.end() ? NotADigit: it->second;
}

void Soundex::encodeTail(std::string& encoding, const std::string& word) const
{
    for (auto i = 1u; i < word.length(); ++i)
        if (!isComplete(encoding))
            encodeLetter(encoding, word[i], word[i - 1]);
}

bool Soundex::isComplete(const std::string& encoding) const
{
    return encoding.length() == MaxCodeLength;
}

void Soundex::encodeLetter(std::string& encoding, char letter, char lastLetter) const
{
    auto digit = encodedDigit(letter);
    if (digit != NotADigit &&
        (digit != lastDigit(encoding) || charutil::isVowel(lastLetter)))
    {
        encoding += digit;
    }
}

std::string Soundex::lastDigit(const std::string& encoding) const
{
    if (encoding.empty()) return NotADigit;
    return std::string(1, encoding.back());
}
