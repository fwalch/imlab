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

