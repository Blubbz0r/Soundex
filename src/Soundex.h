#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

/*!
 * \brief Implements the Soundex algorithm using the following rules:
 *          - b, f, p, v -> 1
 *          - c, g, j, k, q, s, x, z -> 2
 *          - d, t -> 3
 *          - l -> 4
 *          - m, n -> 5
 *          - r -> 6
 */
class Soundex
{
public:
    std::string encode(const std::string& word) const;

    std::string encodedDigit(char letter) const;

private:
    std::string encodedDigits(const std::string& word) const;
    void encodeHead(std::string& encoding, const std::string& word) const;
    void encodeTail(std::string& encoding, const std::string& word) const;
    bool isComplete(const std::string& encoding) const;
    void encodeLetter(std::string& encoding, char letter, char lastLetter) const;
    std::string lastDigit(const std::string& encoding) const;
};

#endif // SOUNDEX_H
