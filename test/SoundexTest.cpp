#include "gmock/gmock.h"

#include "Soundex.h"

using testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    Soundex soundex;
    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}
