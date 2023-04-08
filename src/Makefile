CC = g++
CFLAGS = -Wall
FLAGS = -lstdc++
CSTD = -std=c++11

SAFETORRENT = safetorrent
OBJ1 = safetorrent.cpp
OBJ2 = torrent.cpp

all: $(SAFETORRENT)
$(SAFETORRENT): $(OBJ1) $(OBJ2)
		$(CC) $(CSTD) -o $(SAFETORRENT) $(OBJ1) $(OBJ2) $(FLAGS)

clean:
		rm -f $(SAFETORRENT) *.o