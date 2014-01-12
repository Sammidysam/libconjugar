CC=gcc

FLAGS=-std=c11
TEST_FLAGS=-lcheck
COMPILE_FLAGS=-fPIC
LINK_FLAGS=

SO_FILE=bin/libconjugar.so
TEST_FILE=bin/test

# All of the objects to be put into the SO_FILE.
# Make sure to put in alphabetical order!
OBJECTS=$(addprefix obj/,stem.o verb.o)
TEST_OBJECTS=$(addprefix obj/,test.o)

all: $(SO_FILE) $(TEST_FILE)

include files.mk
