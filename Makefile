CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -O2

TARGETS = nfl temp_converter
SOURCES = nfl.c temp_converter.c

.PHONY: all clean

all: $(TARGETS)

nfl: nfl.c
	$(CC) $(CFLAGS) -o $@ $<

temp_converter: temp_converter.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) *.o