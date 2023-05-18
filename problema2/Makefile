CC = gcc -Wall -Wextra -g
CFLAGS = -c

.PHONY: build
pb2: mainPB2.o distances.o
	cat $(input) > "date.in"
	$(CC) $^ -o $@

mainPB2.o: mainPB2.c
	$(CC) $(CFLAGS) $< -o $@

distances.o: distances.c
	$(CC) $(CFLAGS) $< -o $@

run: pb2
	./pb2

.PHONY: clean
clean:
	rm -rf *.o pb2 mainPB2.o distances.o date.in date.out
