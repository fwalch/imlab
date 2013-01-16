#include <gtest/gtest.h>
#include "../src/import.h"
#include "../src/oltp.h"
#include "../src/olap.h"

TEST(Integration, TPCE) {
  Tpce tpce;

  ASSERT_EQ(0, tpce.customers.count());

  importSampleData("test/data", &tpce);

  // Test if querying retrieves the correct object
  auto c_tid = tpce.customers.get(433);
  auto c_sid = tpce.customers.c_l_name[c_tid];
  ASSERT_TRUE(memcmp(tpce.customers.c_l_name_dict.get(c_sid), "Labree", 6) == 0);
}

TEST(Integration, Yaga) {
  Yago yago;

  ASSERT_EQ(0, yago.facts.count());

  importSampleData("test/data", &yago);

  ASSERT_TRUE(strcmp("Jefferson County, Texas", yago.facts.subject_dict.get(yago.facts.subject[1])) == 0);
  ASSERT_TRUE(strcmp("owns", yago.facts.predicate_dict.get(yago.facts.predicate[1])) == 0);
  ASSERT_TRUE(strcmp("Jack Brooks Regional Airport", yago.facts.object_dict.get(yago.facts.object[1])) == 0);
}

TEST(Integration, TPCC) {
  Tpcc tpcc;

  ASSERT_EQ(0, tpcc.warehouses.count());
  ASSERT_EQ(0, tpcc.customers.count());
  ASSERT_EQ(0, tpcc.districts.count());
  ASSERT_EQ(0, tpcc.stock.count());
  ASSERT_EQ(0, tpcc.items.count());
  ASSERT_EQ(0, tpcc.orders.count());
  ASSERT_EQ(0, tpcc.orderLines.count());
  ASSERT_EQ(0, tpcc.newOrders.count());
  ASSERT_EQ(0, tpcc.history.count());

  importSampleData("test/data", &tpcc);

  // Test if querying retrieves the correct object
  auto o_tid = tpcc.orders.get(4, 1, 8);
  ASSERT_EQ(4, tpcc.orders.o_w_id[o_tid]);
  ASSERT_EQ(1, tpcc.orders.o_d_id[o_tid]);
  ASSERT_EQ(8, tpcc.orders.o_id[o_tid]);
  ASSERT_EQ(8, tpcc.orders.o_c_id[o_tid]);

  // Check query
  ASSERT_EQ(23000, lastNameOrderSum("BARBARBAR", &tpcc));

  // Verify that warehouse 4 originally has 50 items of type 1:
  auto s_tid = tpcc.stock.get(4, 1);
  ASSERT_EQ(50, tpcc.stock.s_quantity[s_tid]);

  int supware[2] = { 4 };
  int itemid[2] = { 1 };
  int qty[2] = { 10 };
  tpcc.newOrder(4, 1, 1, 1, supware, itemid, qty, 0);

  // Verify execution of NewOrder transaction:
  // we created a new order on warehouse 4, district 1 for customer 1
  // for 1 item of type 1. The item is in warehouse 4 (supware) and we want 10
  // more items. In the sample data there are originally 50 items.
  // -> now only 40 items of type 1 should be in warehouse 4:
  s_tid = tpcc.stock.get(4, 1);
  ASSERT_EQ(40, tpcc.stock.s_quantity[s_tid]);
  ASSERT_EQ(16, tpcc.orders.count());

  auto c_tid = tpcc.customers.get(4, 1, 1);
  ASSERT_EQ(-1000, tpcc.customers.c_balance[c_tid]);
  ASSERT_EQ(16, tpcc.newOrders.count());
  tpcc.delivery(4, 101, 0);
  ASSERT_EQ(0, tpcc.customers.c_balance[c_tid]);
  ASSERT_EQ(15, tpcc.newOrders.count());
}

