CC=g++
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
# OBJS=obj/allocator.o obj/memtest.o
BINDIR = bin
BIN = bin/main
SUBMITNAME=project5.zip

all:$(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submin:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)

run: $(BIN)
	./$(BIN)

debug:
	$(info $$SRCS = $(SRCS))
	$(info $$OBJS = $(OBJS))