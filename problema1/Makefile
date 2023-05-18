CC = gcc -Wall -Wextra -g
CFLAGS = -c

.PHONY: build
pb1: mainPB1.o cycleDetection.o
	cat $(input) > "date.in"
	$(CC) $^ -o $@

mainPB1.o: mainPB1.c
	$(CC) $(CFLAGS) $< -o $@

cycleDetection.o: cycleDetection.c
	$(CC) $(CFLAGS) $< -o $@

run: pb1
	./pb1

.PHONY: clean
clean:
	rm -rf *.o pb1 mainPB1.o cycleDetection.o date.in date.out
