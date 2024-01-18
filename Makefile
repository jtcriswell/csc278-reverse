CC := clang

all: reverse

reverse: reverse.c
	$(CC) -o $@ $<

clean:
	rm -f *.o reverse
