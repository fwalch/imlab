#include <gtest/gtest.h>
#include "../../src/str/dictionary.h"
#include <climits>

TEST(StringDictionary, GetString) {
  auto dic = str::dictionary();
  auto sid = dic.insert("SomeString");

  ASSERT_EQ(sid, dic.get("SomeString"));
  ASSERT_TRUE(strcmp("SomeString", dic.get(sid)) == 0);
}

TEST(StringDictionary, RemoveString) {
  auto dic = str::dictionary();
  auto sid = dic.insert("SomeString");
  dic.remove(sid);

  ASSERT_EQ(0, dic.get("SomeString"));
  ASSERT_EQ(NULL, dic.get(sid));
}

TEST(StringDictionary, GetReturnsUpdatedString) {
  auto dic = str::dictionary();
  auto sid = dic.insert("SomeString");
  dic.update(sid, "SomeOtherString");

  ASSERT_EQ(0, dic.get("SomeString"));
  ASSERT_EQ(sid, dic.get("SomeOtherString"));
  ASSERT_TRUE(strcmp("SomeOtherString", dic.get(sid)) == 0);
}

TEST(StringDictionary, InsertDoesNotReturnZeroSID) {
  auto dic = str::dictionary();
  ASSERT_NE(0, dic.insert("SomeString"));
}

TEST(StringDictionary, InsertMultipleStrings) {
  auto dic = str::dictionary();
  auto sid1 = dic.insert("SomeString");
  auto sid2 = dic.insert("SomeString");
  ASSERT_EQ(sid1, sid2);
}

TEST(StringDictionary, RemoveMultipleStrings) {
  auto dic = str::dictionary();
  auto sid = dic.insert("SomeString");
  dic.insert("SomeString");
  dic.insert("SomeString");

  ASSERT_EQ(sid, dic.get("SomeString"));
  dic.remove(sid);
  ASSERT_EQ(sid, dic.get("SomeString"));
  dic.remove(sid);
  ASSERT_EQ(sid, dic.get("SomeString"));
  dic.remove(sid);
  ASSERT_EQ(0, dic.get("SomeString"));
}

TEST(StringDictionary, UpdateCreatesNewString) {
  auto dic = str::dictionary();
  auto sid1 = dic.insert("SomeString");
  auto sid2 = dic.insert("SomeString");

  dic.update(sid1, "SomeOtherString");
  ASSERT_NE(sid1, sid2);
}

TEST(StringDictionary, GetOriginalAndUpdatedString) {
  auto dic = str::dictionary();
  auto sid1 = dic.insert("SomeString");
  auto sid2 = dic.insert("SomeString");
  dic.update(sid2, "SomeOtherString");

  ASSERT_EQ(sid1, dic.get("SomeString"));
  ASSERT_EQ(sid2, dic.get("SomeOtherString"));
}

TEST(StringDictionary, DeleteOriginalAndUpdatedString) {
  auto dic = str::dictionary();
  auto sid1 = dic.insert("SomeString");
  auto sid2 = dic.insert("SomeString");
  dic.update(sid2, "SomeOtherString");

  dic.remove(sid1);
  dic.remove(sid2);
  ASSERT_EQ(0, dic.get("SomeString"));
  ASSERT_EQ(0, dic.get("SomeOtherString"));
}

TEST(StringDictionary, MakeShortString) {
  auto dic = str::dictionary();
  auto string = dic.make_string("SomeString");
  ASSERT_EQ(10, string.len);
  ASSERT_TRUE(memcmp(string.value, "SomeString", 10) == 0);
}

TEST(StringDictionary, MakeLongString) {
  auto dic = str::dictionary();
  auto str = "SomeLooooooooooooooooooooooooooooongString";
  auto string = dic.make_string(str);
  ASSERT_EQ(0xFF, string.len);
  ASSERT_TRUE(memcmp(string.head, str, 3) == 0);
  ASSERT_EQ(42, string.length);
  ASSERT_TRUE(strcmp(dic.get(string.sid), str) == 0);
}

TEST(StringDictionary, GetLongString) {
  auto dic = str::dictionary();
  auto str = "SomeLooooooooooooooooooooooooooooongString";
  auto string = dic.make_string(str);
  ASSERT_TRUE(strcmp(dic.get(string), str) == 0);
}

TEST(StringDictionary, GetShortString) {
  auto dic = str::dictionary();
  auto str = "SomeString";
  auto string = dic.make_string(str);
  ASSERT_TRUE(strcmp(dic.get(string), str) == 0);
}

TEST(StringDictionary, UpdateStringWithSameLength) {
  auto dic = str::dictionary();
  auto str1 = "asdf";
  auto str2 = "asdg";

  uint64_t sid = dic.insert(str1);
  const char* strPtr = dic.get(sid);
  ASSERT_TRUE(strcmp(str1, strPtr) == 0);

  uint64_t previousSid = sid;
  dic.update(sid, str2);

  ASSERT_EQ(previousSid, sid);
  ASSERT_TRUE(strcmp(str2, strPtr) == 0);

  ASSERT_TRUE(strcmp(dic.get(sid), str2) == 0);
}

TEST(StringDictionary, EmptyString) {
  auto dic = str::dictionary();
  auto sid = dic.insert("");

  ASSERT_NE(str::dictionary::NO_VALUE, sid);
  ASSERT_FALSE(str::dictionary::NO_STRING == dic.get_string(""));
  ASSERT_FALSE(str::dictionary::NO_STRING == dic.make_string(""));
}

TEST(StringDictionary, GetStringDoesNotInsert) {
  auto dic = str::dictionary();
  auto sid = dic.insert("");

  ASSERT_NE(str::dictionary::NO_VALUE, sid);
  ASSERT_FALSE(str::dictionary::NO_STRING == dic.get_string(""));
  ASSERT_FALSE(str::dictionary::NO_STRING == dic.make_string(""));
}
