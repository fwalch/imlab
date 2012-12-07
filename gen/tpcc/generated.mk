TPCC_SRC_FILES = warehouse.cpp district.cpp customer.cpp history.cpp neworder.cpp order.cpp orderline.cpp item.cpp stock.cpp
TPCC_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(TPCC_SRC_FILES))

TPCC_OBJ_DIR = $(OBJ_DIR)/gen/tpcc
TPCC_OBJ_FILES = $(TPCC_SRC_FILES:.cpp=.o)
TPCC_OBJECTS = $(addprefix $(TPCC_OBJ_DIR)/, $(TPCC_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(TPCC_SRC_FILES))
OBJECTS += $(addprefix $(TPCC_OBJ_DIR)/, $(TPCC_OBJ_FILES))

$(TPCC_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
