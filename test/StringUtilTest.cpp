#include "gmock/gmock.h"

#include "StringUtil.h"

using namespace stringutil;
using testing::Eq;

TEST(AString, AnswersHeadAsItsFirstLetter)
{
   ASSERT_THAT(head("xyz"), Eq("x"));
}

TEST(AString, AnswersHeadAsEmptyWhenEmpty)
{
   ASSERT_THAT(head(""), Eq(""));
}

TEST(AString, AnswersTailAsAllLettersAfterHead)
{
   ASSERT_THAT(tail("xyz"), Eq("yz"));
}

TEST(AString, AnswersTailAsEmptyWhenEmpty)
{
   ASSERT_THAT(tail(""), Eq(""));
}

TEST(AString, AnswersTailAsEmptyWhenContainsOnlyOneCharacter)
{
   ASSERT_THAT(tail("X"), Eq(""));
}
