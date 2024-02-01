CFILE=$(wildcard *.c)
OUTPUTS=$(patsubst %.c,%.exe,$(CFILE))
OPT=-O3


all: $(OUTPUTS)

%.exe: %.c
	gcc $^ -o $@ $(OPT)

clean:
	rm $(OUTPUTS)
