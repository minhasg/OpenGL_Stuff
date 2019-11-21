CC = g++
OPENGL_LINKS = -lglfw -lGLEW -lGLU -lGL
SOURCE = ./src
BINARY = ./bin
INCLUDE = ./include

all:
	$(CC) -I$(INCLUDE) $(SOURCE)/*.cpp -o $(BINARY)/Hurh $(OPENGL_LINKS) 

delete:
	rm $(BINARY)/*
