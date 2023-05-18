CC = gcc -Wall -Wextra -g
CFLAGS = -c

.PHONY: build
pb3: mainPB3.o smecheria.o
	cat $(input) > "date.in"
	$(CC) $^ -o $@

mainPB3.o: mainPB3.c
	$(CC) $(CFLAGS) $< -o $@

smecheria.o: smecheria.c
	$(CC) $(CFLAGS) $< -o $@

run: pb3
	./pb3

.PHONY: clean
clean:
	rm -rf *.o pb3 mainPB3.o smecheria.o date.in date.out
