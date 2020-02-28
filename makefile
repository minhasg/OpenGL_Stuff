CC = g++
OPENGL_LINKS = -lglfw -lGLEW -lGLU -lGL
SOURCE = ./src
BINARY = ./bin
TESTS_BINARY = $(BINARY)/tests
INCLUDE = ./include
TESTS = ./tests
TESTS_INCLUDE = $(INCLUDE)/tests
OBJ_BUILD_FLAGS = $(OPENGL_LINKS) -I$(INCLUDE) -Wall
TESTS_BUILD_FLAGS = $(OPENGL_LINKS) -I$(TESTS_INCLUDE) -Wall
EXECUTABLE = Hurh

tests: TestData.o UtilsTest.o
	@echo "Building the tester program. This is a separate executable from $(EXECUTABLE) excusively for running unit tests."
	@-$(CC) $(TESTS)/testMain.cpp $(BINARY)/*.o $(TESTS_BINARY)/*.o -o $(BINARY)/testMain $(TESTS_BUILD_FLAGS)

TestData.o:
	@-$(CC) -c $(TESTS)/TestData.cpp -o $(TESTS_BINARY)/TestData.o $(TESTS_BUILD_FLAGS)

UtilsTest.o: Utils.o
	@-$(CC) -c $(TESTS)/UtilsTest.cpp -o $(TESTS_BINARY)/UtilsTest.o $(TESTS_BUILD_FLAGS) $(OBJ_BUILD_FLAGS)

###########################################################
# TARGETS FOR TESTING ABOVE, TARGETS FOR MAIN BUILD BELOW #
###########################################################

build: Triangle.o Rectangle.o Window.o
	@echo "Running main build target"
	@-$(CC) -I$(INCLUDE) $(BINARY)/*.o $(SOURCE)/main.cpp -o $(BINARY)/$(EXECUTABLE) $(OPENGL_LINKS) 

Triangle.o: Drawable.o Transformable.o
	@echo "Building Triangle.cpp"
	@-$(CC) -c $(SOURCE)/Triangle.cpp -o $(BINARY)/Triangle.o $(OBJ_BUILD_FLAGS)

Shader.o: Utils.o
	@echo "Building Shader.cpp"
	@-$(CC) -c $(SOURCE)/Shader.cpp -o $(BINARY)/Shader.o $(OBJ_BUILD_FLAGS)
    
Drawable.o: Shader.o Texture.o
	@echo "Building Drawable.cpp"
	@-$(CC) -c $(SOURCE)/Drawable.cpp -o $(BINARY)/Drawable.o $(OBJ_BUILD_FLAGS)

Utils.o:
	@echo "Building Utils.cpp"
	@-$(CC) -c $(SOURCE)/Utils.cpp -o $(BINARY)/Utils.o $(OBJ_BUILD_FLAGS)

Rectangle.o: Drawable.o
	@echo "Building Rectangle.cpp"
	@-$(CC) -c $(SOURCE)/Rectangle.cpp -o $(BINARY)/Rectangle.o $(OBJ_BUILD_FLAGS)

Texture.o: 	
	@echo "Building Texture.cpp"
	@-$(CC) -c $(SOURCE)/Texture.cpp -o $(BINARY)/Texture.o $(OBJ_BUILD_FLAGS)

Transformable.o: 	
	@echo "Building Transformable.cpp"
	@-$(CC) -c $(SOURCE)/Transformable.cpp -o $(BINARY)/Transformable.o $(OBJ_BUILD_FLAGS)

Window.o: 	
	@echo "Building Window.cpp"
	@-$(CC) -c $(SOURCE)/Window.cpp -o $(BINARY)/Window.o $(OBJ_BUILD_FLAGS)

Camera.o:
	@echo "Building Camera.cpp"
	@-$(CC) -c $(SOURCE)/Camera.cpp -o $(BINARY)/Camera.o $(OBJ_BUILD_FLAGS)

clean:
	rm $(BINARY)/*.o $(TESTS_BINARY)/*.o 
