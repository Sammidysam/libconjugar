CC=gcc

FLAGS=-std=c11
TEST_FLAGS=-lcheck $(SO_FILE)
COMPILE_FLAGS=-fPIC
LINK_FLAGS=

SO_FILE=bin/libconjugar.so
TEST_FILE=bin/test.$(shell arch)

# All of the objects to be put into the SO_FILE.
# Make sure to put in alphabetical order!
OBJECTS=$(addprefix obj/,stem.o verb.o)
TEST_OBJECTS=$(addprefix obj/,test.o test_stem.o test_verb.o)

all: $(SO_FILE) $(TEST_FILE)

clean:
	rm $(OBJECTS) $(TEST_OBJECTS) $(SO_FILE) $(TEST_FILE)

include files.mk
