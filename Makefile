# Redefine CXX only if not passed from environment variable
ifeq ($(origin CXX), default)
	CXX = clang++
	CXXFLAGS += -g -Weverything -Wno-c++98-compat -Wno-shadow -Wno-disabled-macro-expansion -Wno-gnu --std=c++11
endif

ifdef release
	CXXFLAGS += -O3
	LDFLAGS +=
else
	CXXFLAGS += -O0
	LDFLAGS +=
endif

include main.mk test.mk
