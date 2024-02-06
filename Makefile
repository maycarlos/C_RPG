COMPILER = clang
COMPILER_FLAGS = -Wall -Wextra -pedantic
INCLUDE_PATH = -Iinclude/
SOURCE = src/*.c
TARGET = c_rpg


run: build
	./$(TARGET)

build: src/main.c
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH) -o c_rpg $(SOURCE)

clean: main
	rm $(TARGET)
