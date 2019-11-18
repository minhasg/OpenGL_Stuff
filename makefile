CC = g++
OPENGL_LINKS = -lglfw -lGLEW -lGLU -lGL
SOURCE = ./src
BINARY = ./bin/

all:
	$(CC) $(SOURCE)/*.cpp -o $(BINARY)Hurh $(OPENGL_LINKS)

delete:
	rm $(BINARY)*
