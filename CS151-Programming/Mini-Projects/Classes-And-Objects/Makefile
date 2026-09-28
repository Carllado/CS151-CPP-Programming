CC=g++
CFLAGS=-g -I.
DEPS = pet.hpp
OBJ = main.o pet.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) run