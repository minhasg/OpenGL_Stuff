CC = g++
OPENGL_LINKS = -lglfw -lGLEW -lGLU -lGL
SOURCE = ./src
BINARY = ./bin
INCLUDE = ./include
OBJ_BUILD_FLAGS = $(OPENGL_LINKS) -I$(INCLUDE) -Wall

all: Triangle.o
	$(CC) -I$(INCLUDE) $(BINARY)/*.o $(SOURCE)/main.cpp -o $(BINARY)/Hurh $(OPENGL_LINKS) 

Triangle.o:
	$(CC) -c $(SOURCE)/Triangle.cpp -o $(BINARY)/Triangle.o $(OBJ_BUILD_FLAGS)

Shader.o:
	echo "Building Shader.cpp"
	$(CC) -c $(SOURCE)/Shader.cpp -o $(BINARY)/Shader.o $(OBJ_BUILD_FLAGS)
    
Drawable2D.o: Shader.o
	echo "Building Drawable2D.cpp"
	$(CC) -c $(SOURCE)/Drawable2D.cpp -o $(BINARY)/Drawable2D.o $(OBJ_BUILD_FLAGS)

clean:
	rm $(BINARY)/*
