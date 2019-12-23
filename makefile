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

build: Triangle.o
	@echo "Running main build target"
	@-$(CC) -I$(INCLUDE) $(BINARY)/*.o $(SOURCE)/main.cpp -o $(BINARY)/$(EXECUTABLE) $(OPENGL_LINKS) 

Triangle.o: Drawable2D.o
	@echo "Building Triangle.cpp"
	@-$(CC) -c $(SOURCE)/Triangle.cpp -o $(BINARY)/Triangle.o $(OBJ_BUILD_FLAGS)

Shader.o:
	@echo "Building Shader.cpp"
	@-$(CC) -c $(SOURCE)/Shader.cpp -o $(BINARY)/Shader.o $(OBJ_BUILD_FLAGS)
    
Drawable2D.o: Shader.o
	@echo "Building Drawable2D.cpp"
	@-$(CC) -c $(SOURCE)/Drawable2D.cpp -o $(BINARY)/Drawable2D.o $(OBJ_BUILD_FLAGS)

Utils.o:
	@echo "Building Utils.cpp"
	@-$(CC) -c $(SOURCE)/Utils.cpp -o $(BINARY)/Utils.o $(OBJ_BUILD_FLAGS)

clean:
	rm $(BINARY)/*.o $(TESTS_BINARY)/*.o 
