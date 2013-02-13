#include <gtest/gtest.h>
#include "../../src/str/dictionary.h"

TEST(String, HasSize16) {
  ASSERT_EQ(16, sizeof(str::string));
}

TEST(String, EmptyStringNotEqualNoString) {
  str::string string;

  ASSERT_FALSE(string == str::dictionary::NO_STRING);
}

TEST(ShortString, EqualComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdf");
  ASSERT_LT(strlen(dict.get(ref)), 16); // just to make sure the test is valid

  auto str2 = dict.make_string("asdf");

  ASSERT_TRUE(ref == str2);
  ASSERT_TRUE(str2 == ref);

  str2 = dict.make_string("asdfa");
  ASSERT_FALSE(ref == str2);
  ASSERT_FALSE(str2 == ref);
}

TEST(LongString, EqualComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdfasdfasdfasdfasdfasdf");
  ASSERT_GT(strlen(dict.get(ref)), 16); // just to make sure the test is valid

  auto str2 = dict.make_string("asdfasdfasdfasdfasdfasdf");
  ASSERT_TRUE(ref == str2);
  ASSERT_TRUE(str2 == ref);

  str2 = dict.make_string("asdfasdfadsfasdfasdfadsfasdfa");
  ASSERT_FALSE(ref == str2);
  ASSERT_FALSE(str2 == ref);
}

TEST(ShortString, LessComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdf");
  ASSERT_LT(strlen(dict.get(ref)), 16); // just to make sure the test is valid

  auto str2 = dict.make_string("asdf");
  ASSERT_FALSE(dict.less(ref, str2));
  ASSERT_FALSE(dict.less(str2, ref));

  str2 = dict.make_string("asdfa");
  ASSERT_TRUE(dict.less(ref, str2));
  ASSERT_FALSE(dict.less(str2, ref));
}

TEST(LongString, LessComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdfasdfasdfasdfasdfasdf");
  ASSERT_GT(strlen(dict.get(ref)), 16); // just to make sure the test is valid

  auto str2 = dict.make_string("asdfasdfasdfasdfasdfasdf");
  ASSERT_FALSE(dict.less(ref, str2));
  ASSERT_FALSE(dict.less(str2, ref));

  str2 = dict.make_string("asdfasdfasdfasdfasdfasdfa");
  ASSERT_TRUE(dict.less(ref, str2));
  ASSERT_FALSE(dict.less(str2, ref));
}

TEST(LongShortString, EqualComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdfasdfasdfasdfasdfasdf");
  ASSERT_GT(strlen(dict.get(ref)), 16); // just to make sure the test is valid

  auto str2 = dict.make_string("asdf");
  ASSERT_FALSE(ref == str2);
  ASSERT_FALSE(str2 == ref);
}

TEST(LongShortString, LessComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("asdfasdfasdfasdfasdfasdf");
  const auto ref2 = dict.make_string("asdfa");

  // just to make sure the test is valid
  ASSERT_GT(strlen(dict.get(ref)), 16);
  ASSERT_LT(strlen(dict.get(ref2)), 16);

  auto str2 = dict.make_string("asdf");

  ASSERT_FALSE(dict.less(ref, str2));
  ASSERT_TRUE(dict.less(str2, ref));

  ASSERT_FALSE(dict.less(ref2, str2));
  ASSERT_TRUE(dict.less(str2, ref2));
}

TEST(VeryShortString, EqualComparison) {
  str::dictionary dict;

  const auto ref = dict.make_string("a");
  ASSERT_LT(strlen(dict.get(ref)), 3); // just to make sure the test is valid

  auto str2 = dict.make_string("b");
  ASSERT_FALSE(ref == str2);
  ASSERT_FALSE(str2 == ref);
}

TEST(VeryShortString, LessComparison) {
  str::dictionary dict;

  const auto str1 = dict.make_string("a");
  const auto str2 = dict.make_string("ab");
  const auto str3 = dict.make_string("b");

  // just to make sure the test is valid
  ASSERT_LT(strlen(dict.get(str1)), 3);
  ASSERT_LT(strlen(dict.get(str2)), 3);
  ASSERT_LT(strlen(dict.get(str3)), 3);

  ASSERT_TRUE(dict.less(str1, str2));
  ASSERT_TRUE(dict.less(str1, str3));
  ASSERT_TRUE(dict.less(str2, str3));

  ASSERT_FALSE(dict.less(str2, str1));
  ASSERT_FALSE(dict.less(str3, str1));
  ASSERT_FALSE(dict.less(str3, str3));
}