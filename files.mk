obj/%.o:
	$(CC) -c -o $@ $< $(FLAGS) $(COMPILE_FLAGS)

$(SO_FILE): $(OBJECTS)
	$(CC) -shared -o $(SO_FILE) $(OBJECTS) $(FLAGS) $(LINK_FLAGS)

# List all of the objects and their dependencies.
# All must be in variable $(OBJECTS).
