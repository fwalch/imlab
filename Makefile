CC = clang++
ifdef release
	CFLAGS = -g -O3 -Weverything -Wno-c++98-compat -Wno-shadow --std=c++11
	LDFLAGS =
else
	CFLAGS = -g -O0 -Weverything -Wno-c++98-compat -Wno-shadow --std=c++11
	LDFLAGS =
endif

include main.mk test.mk

clean:
	rm -rf $(OBJ_DIR) docu

docu: $(SOURCES)
	doxygen Doxyfile
