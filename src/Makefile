TARGETS = $(patsubst %.c, %, $(wildcard *.c))
TARGETS +=$(patsubst %.cpp, %, $(wildcard *.cpp))

all:$(TARGETS)

clean:
	    rm -rf $(TARGETS)
