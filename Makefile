CC = clang++
ifdef release
	CFLAGS = -g -O3 -Wall --std=c++11
	LDFLAGS =
else
	CFLAGS = -g -O0 -Wall --std=c++11
	LDFLAGS =
endif

SRC_DIR = src
SRC_FILES = schema/conversion.cpp \
						schema/warehouse.cpp schema/district.cpp schema/customer.cpp schema/history.cpp \
						schema/neworder.cpp schema/order.cpp schema/orderline.cpp schema/item.cpp schema/stock.cpp \
						schema/store.cpp import.cpp tpcc.cpp oltp.cpp timer.cpp main.cpp
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

EXECUTABLE = $(OBJ_DIR)/fakedb

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CC) $(CFLAGS) -c $< -o $@

