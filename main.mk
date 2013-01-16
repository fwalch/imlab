SRC_DIR = src
SRC_FILES = schema/conversion.cpp schema/store.cpp \
						import.cpp tpcc.cpp oltp.cpp olap.cpp timer.cpp \
						str_dictionary.cpp
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
MAIN_OBJ = $(OBJ_DIR)/main.o

GEN_SRC_DIR = gen/tpcc
include $(GEN_SRC_DIR)/generated.mk
include $(GEN_SRC_DIR)/generated_queries.mk

GEN_SRC_DIR = gen/tpce
include $(GEN_SRC_DIR)/generated.mk

GEN_SRC_DIR = gen/yago
include $(GEN_SRC_DIR)/generated.mk

EXECUTABLE = $(OBJ_DIR)/fakedb

all: $(EXECUTABLE)

clean:
	rm -rf $(OBJ_DIR)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(MAIN_OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CXXFLAGS) -c $< -o $@
