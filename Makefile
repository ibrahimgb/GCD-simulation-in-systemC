include Makefile.config

PROJECT := pgcd
SRCS    := $(wildcard *.cpp)
OBJS    := $(SRCS:.cpp=.o)

include Makefile.rules
