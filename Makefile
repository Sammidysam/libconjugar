CC=gcc

FLAGS=-std=c11
COMPILE_FLAGS=-fPIC
LINK_FLAGS=

SO_FILE=bin/libconjugar.so

# All of the objects to be put into the SO_FILE.
# Make sure to put in alphabetical order!
OBJECTS=$(addprefix obj/,stem.o verb.o)

all: $(SO_FILE)

include files.mk
