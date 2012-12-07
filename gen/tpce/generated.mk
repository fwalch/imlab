TPCE_SRC_FILES = account_permission.cpp customer.cpp
TPCE_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(TPCE_SRC_FILES))

TPCE_OBJ_DIR = $(OBJ_DIR)/gen/tpce
TPCE_OBJ_FILES = $(TPCE_SRC_FILES:.cpp=.o)
TPCE_OBJECTS = $(addprefix $(TPCE_OBJ_DIR)/, $(TPCE_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(TPCE_SRC_FILES))
OBJECTS += $(addprefix $(TPCE_OBJ_DIR)/, $(TPCE_OBJ_FILES))

$(TPCE_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
