#ifndef _IMPORT_H_
#define _IMPORT_H_

#include <string>
#include "tpcc.h"
#include "tpce.h"
#include "yago.h"

void importSampleData(std::string, Tpcc*);
void importSampleData(std::string, Tpce*);
void importSampleData(std::string, Yago*);

#endif
