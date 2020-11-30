CXX = g++ -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -Wsign-conversion -std=c++11 -g
TAR = tar -c
ZIP = xz -k9evv

hdr := $(wildcard *.h)
src := $(wildcard *.cpp)
obj := $(src:%.cpp=%.o)
out := main
tar := archive.tar
arc := $(wildcard archive.*)

$(out): $(obj)
	$(CXX) $(CXXFLAG) -o $@ $^ -lm

$(tar): $(hdr) $(src)
	$(TAR) -f $@ $^

.PHONY: zip clean

zip: $(tar)
	$(ZIP) $^

clean:
	-rm -f $(obj) $(out) $(arc)
