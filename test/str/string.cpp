#include <gtest/gtest.h>
#include "../../src/str/dictionary.h"

TEST(String, HasSize16) {
  ASSERT_EQ(16, sizeof(str::string));
}

TEST(String, EqualComparison) {
  str::string string1;
  string1.len = 14;
  strcpy(string1.value, "abcdefghijklmn");

  str::string string2;
  string2.len = 14;
  strcpy(string2.value, "abcdefghijklmn");

  ASSERT_FALSE(string1 < string2);
  ASSERT_FALSE(string2 < string1);
  ASSERT_TRUE(string1 == string2);
}

TEST(String, LessThanComparison) {
  str::string string1;
  string1.len = 13;
  strcpy(string1.value, "abcdefghijklm");

  str::string string2;
  string2.len = 14;
  strcpy(string2.value, "abcdefghijklmn");

  ASSERT_TRUE(string1 < string2);
  ASSERT_FALSE(string2 < string1);
  ASSERT_FALSE(string1 == string2);
}

TEST(String, GreaterThanComparison) {
  str::string string1;
  string1.len = 14;
  strcpy(string1.value, "abcdefghijklmn");

  str::string string2;
  string2.len = 13;
  strcpy(string2.value, "abcdefghijklm");

  ASSERT_FALSE(string1 < string2);
  ASSERT_TRUE(string2 < string1);
  ASSERT_FALSE(string1 == string2);
}

