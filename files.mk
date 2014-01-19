obj/%.o:
	$(CC) -c -o $@ $< $(FLAGS) $(COMPILE_FLAGS)

$(SO_FILE): $(OBJECTS)
	$(CC) -shared -o $(SO_FILE) $(OBJECTS) $(FLAGS) $(LINK_FLAGS)

$(TEST_FILE): $(TEST_OBJECTS) $(SO_FILE)
	$(CC) -o $(TEST_FILE) $(TEST_OBJECTS) $(FLAGS) $(TEST_FLAGS)

# Program objects.
obj/stem.o: $(addprefix src/,stem.c stem.h) $(addprefix obj/,verb.o)
obj/verb.o: $(addprefix src/,verb.c verb.h)

# Test objects.
obj/test.o: $(addprefix test/,test.c)
obj/test_stem.o: $(addprefix test/,test_stem.c test_stem.h) $(addprefix obj/,stem.o)
obj/test_verb.o: $(addprefix test/,test_verb.c test_verb.h) $(addprefix obj/,verb.o)
