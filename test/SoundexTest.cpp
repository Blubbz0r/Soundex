#include "gmock/gmock.h"

#include "Soundex.h"

using testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A"));
}
