TEST_CFLAGS = $(CFLAGS) -Wno-global-constructors
TEST_LDFLAGS = $(LDFLAGS)

TEST_DIR = test
TEST_FILES = main.cpp conversion.cpp
TEST_SOURCES = $(addprefix $(TEST_DIR)/, $(TEST_FILES))

TEST_OBJ_DIR = obj/$(TEST_DIR)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)
TEST_OBJECTS = $(addprefix $(TEST_OBJ_DIR)/, $(TEST_OBJ_FILES)) $(TEST_OBJ_DIR)/libgtest.a

TEST_EXECUTABLE = $(TEST_OBJ_DIR)/fakedb_test

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CC) -lpthread $(TEST_LDFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(dir $@) && $(CC) $(TEST_CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_OBJ_DIR)/libgtest.a:
	mkdir -p $(TEST_OBJ_DIR) && cd $(TEST_OBJ_DIR) && cmake /usr/src/gtest && make
