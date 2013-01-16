YAGO_SRC_FILES = triple.cpp
YAGO_SOURCES = $(addprefix $(GEN_SRC_DIR)/, $(YAGO_SRC_FILES))

YAGO_OBJ_DIR = $(OBJ_DIR)/gen/yago
YAGO_OBJ_FILES = $(YAGO_SRC_FILES:.cpp=.o)
YAGO_OBJECTS = $(addprefix $(YAGO_OBJ_DIR)/, $(YAGO_OBJ_FILES))

SOURCES += $(addprefix $(GEN_SRC_DIR)/, $(YAGO_SRC_FILES))
OBJECTS += $(addprefix $(YAGO_OBJ_DIR)/, $(YAGO_OBJ_FILES))

$(YAGO_OBJ_DIR)/%.o: $(GEN_SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
