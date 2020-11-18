CC = gcc -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c11

src = $(wildcard src/*.c)
obj = $(src:%.c=%.o)
out = onecard

$(out): $(obj)
	$(CC) -o $@ $^
	
.PHONY: clean
clean:
	-rm -f $(obj) $(out)
