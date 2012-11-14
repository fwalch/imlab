GEN_SRC_FILES = warehouse.cpp district.cpp customer.cpp history.cpp neworder.cpp order.cpp orderline.cpp item.cpp stock.cpp
GEN_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(GEN_SRC_FILES))

GEN_OBJ_DIR = $(OBJ_DIR)/gen
GEN_OBJ_FILES = $(GEN_SRC_FILES:.cpp=.o)
GEN_OBJECTS = $(addprefix $(GEN_OBJ_DIR)/, $(GEN_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(GEN_SRC_FILES))
OBJECTS += $(addprefix $(GEN_OBJ_DIR)/, $(GEN_OBJ_FILES))

$(GEN_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
