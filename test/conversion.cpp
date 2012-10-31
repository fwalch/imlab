#include <gtest/gtest.h>
#include "../src/schema/conversion.h"

TEST(Conversion, StringToLong) {
  ASSERT_EQ(100, db_stol("1.00"));
  ASSERT_EQ(100, db_stol("10.0"));
  ASSERT_EQ(100, db_stol("100"));
  ASSERT_EQ(-1000, db_stol("-1.000"));
}

TEST(Conversion, StringToDatetime) {
  ASSERT_EQ(100, db_stol("100"));
  ASSERT_EQ(10, db_stol("10"));
}
