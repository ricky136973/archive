CC = gcc -Wall -Wextra -Wpedantic -ansi -std=c99

src = $(wildcard *.c)
obj = $(src:%.c=%.o)
out = main

$(out): $(obj)
	$(CC) -o $@ $^ -lm
	
.PHONY: clean
clean:
	rm $(obj) $(out)
