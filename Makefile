CC = g++
CFLAGS = -Wall -std=c++11
SRC = src/main.cpp src/mail.cpp src/storage.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = mailstack

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean