#ifndef _TPCE_H_
#define _TPCE_H_

#include <string>
#include <cstdint>
#include "../gen/tpce/schema.h"

/**
 * Controller class for TPC-E tables and transactions.
 */
class Tpce {
  public:
    tpce::Customer customers;
    tpce::AccountPermission accountPermissions;
};

#endif
