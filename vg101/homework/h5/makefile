CC  = gcc -Wall -Wextra -Wpedantic -ansi -std=c99
TAR = tar -c
ZIP = xz -k9

hdr = $(wildcard *.h)
src = $(wildcard *.c)
obj = $(src:%.c=%.o)
out = main
tar = archive.tar
arc = $(wildcard archive.*)

$(out): $(obj)
	$(CC) -o $@ $^ -lm

$(tar): $(hdr) $(src)
	$(TAR) -f $@ $^

.PHONY: zip clean

zip: $(tar)
	$(ZIP) $^

clean:
	rm -f $(obj) $(out) $(arc)
