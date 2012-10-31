SRC_DIR = src
SRC_FILES = schema/conversion.cpp \
						schema/warehouse.cpp schema/district.cpp schema/customer.cpp schema/history.cpp \
						schema/neworder.cpp schema/order.cpp schema/orderline.cpp schema/item.cpp schema/stock.cpp \
						schema/store.cpp import.cpp tpcc.cpp oltp.cpp timer.cpp
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
MAIN_OBJ = $(OBJ_DIR)/main.o

EXECUTABLE = $(OBJ_DIR)/fakedb

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(MAIN_OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CXX) $(CFLAGS) -c $< -o $@
