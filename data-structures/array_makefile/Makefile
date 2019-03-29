CC     = clang
CFLAGS = -std=c11 -O2 -Wall -pedantic

SOURCE = $(wildcard *.c *.cc *.cpp *.cxx)
EXT    = $(firstword $(suffix $(SOURCE)))
OBJ    = $(SOURCE:$(EXT)=.o)
DEP    = $(SOURCE:$(EXT)=.d)
BIN    = array

all: array
shell: $(OBJ) $(CC) $(CFLAGS) -o $(OBJ)
%.o: %.c $(CC) $(CFLAGS) -c $<
clean:
	rm $(OBJ) $(BIN)
