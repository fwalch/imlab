SCHEMA_SRC_FILES = warehouse.cpp district.cpp customer.cpp history.cpp neworder.cpp order.cpp orderline.cpp item.cpp stock.cpp
SCHEMA_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(SCHEMA_SRC_FILES))

SCHEMA_OBJ_DIR = $(OBJ_DIR)/gen
SCHEMA_OBJ_FILES = $(SCHEMA_SRC_FILES:.cpp=.o)
SCHEMA_OBJECTS = $(addprefix $(SCHEMA_OBJ_DIR)/, $(SCHEMA_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(SCHEMA_SRC_FILES))
OBJECTS += $(addprefix $(SCHEMA_OBJ_DIR)/, $(SCHEMA_OBJ_FILES))

$(SCHEMA_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
