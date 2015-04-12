#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>

namespace stringutil
{

    std::string zeroPad(const std::string& word, size_t maxLength);

    std::string upperFront(const std::string& string);

    std::string head(const std::string& word);
    std::string tail(const std::string& word);

}

#endif // STRINGUTIL_H
