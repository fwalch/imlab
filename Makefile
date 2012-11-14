# Redefine CXX only if not passed from environment variable
ifeq ($(origin CXX), default)
	CXX = clang++
endif

ifdef release
	CXXFLAGS += -g -O3 -Weverything -Wno-c++98-compat -Wno-shadow -Wno-disabled-macro-expansion --std=c++11
	LDFLAGS +=
else
	CXXFLAGS += -g -O0 -Weverything -Wno-c++98-compat -Wno-shadow -Wno-disabled-macro-expansion--std=c++11
	LDFLAGS +=
endif

include main.mk test.mk
