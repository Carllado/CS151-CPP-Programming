CC=g++
CFLAGS=-g -I. -std=c++11
DEPS = Question.hpp Quiz.hpp
OBJ = main.o Question.o Quiz.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) run quiz.data