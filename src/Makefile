CC = g++
CFLAGS = -Wall
FLAGS = -lstdc++
CSTD = -std=c++11

SAFETORRENT = safetorrent
OBJ1 = safetorrent.o
OBJ2 = torrent.o
OBJ3 = bencoding.o

all: $(SAFETORRENT)
$(SAFETORRENT): $(OBJ1) $(OBJ2) $(OBJ3)
	$(CC) $(CSTD) -o $(SAFETORRENT) $(OBJ1) $(OBJ2) $(OBJ3) $(CFLAGS) $(FLAGS)

$(OBJ1): safetorrent.cpp safetorrent.h
	$(CC) $(CSTD) $(CFLAGS) -c $< -o $(OBJ1)

$(OBJ2): torrent.cpp torrent.h
	$(CC) $(CSTD) $(CFLAGS) -c $< -o $(OBJ2)

$(OBJ3): bencoding.cpp bencoding.h
	$(CC) $(CSTD) $(CFLAGS) -c $< -o $(OBJ3)

clean:
	rm -f $(SAFETORRENT) *.o
