CC=g++
CFLAGS=-I.
DEPS = Huffman.hpp DataTable.hpp
OBJ = main.o Huffman.o DataTable.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

encoder: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
