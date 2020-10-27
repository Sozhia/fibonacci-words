CC=g++
CFLAGS=-I.
DEPS = ../include/fibonacci_words.h
OBJ = ../src/fibonacci_words_main.o

%.o:  %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fibonacci_words: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf ../src/*o fibonacci_words *.txt