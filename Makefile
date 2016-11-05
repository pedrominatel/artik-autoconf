TARGET=artik-autoconfig
INC_DIR=./inc
BIN_DIR=./bin
LIBS= -lm
LDLIBS=
CC=../arm-2010q1/bin/arm-none-linux-gnueabi-gcc
#CC=gcc
CFLAGS=-O0 -Wunused -g3 -Wall -c -I$(INC_DIR)

.PHONY: default all clean

default: $(TARGET)
all: default

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, src/%.o, $(SRC))
HEADERS = $(wildcard src/*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

.PRECIOUS: $(TARGET) $(OBJ)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -static $(LDLIBS) -o $@

clean:
	-rm -f src/*.o
	-rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

