BUILTIN_SRC_FILES = tax_query.cpp lastname_order_sum_query.cpp
BUILTIN_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(BUILTIN_SRC_FILES))

BUILTIN_OBJ_DIR = $(OBJ_DIR)/gen
BUILTIN_OBJ_FILES = $(BUILTIN_SRC_FILES:.cpp=.o)
BUILTIN_OBJECTS = $(addprefix $(BUILTIN_OBJ_DIR)/, $(BUILTIN_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(BUILTIN_SRC_FILES))
OBJECTS += $(addprefix $(BUILTIN_OBJ_DIR)/, $(BUILTIN_OBJ_FILES))

$(BUILTIN_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
