CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

all: day01a day01b

day%: day%.c
	$(CC) $(CFLAGS) -o out_$@ $<

clean:
	rm -fr out_*

.PHONY: all clean

run%: day%
	./out_$<
