obj/%.o:
	$(CC) -c -o $@ $< $(FLAGS) $(COMPILE_FLAGS)

$(SO_FILE): $(OBJECTS)
	$(CC) -shared -o $(SO_FILE) $(OBJECTS) $(FLAGS) $(LINK_FLAGS)

# List all of the objects and their dependencies.
# All must be in variable $(OBJECTS).
# Make sure to put in alphabetical order!
obj/stem.o: src/stem.c src/stem.h src/verb.h
obj/verb.o: src/verb.c src/verb.h src/stem.h
