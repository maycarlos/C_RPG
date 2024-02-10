COMPILER = clang
STANDARD = -std=c17
COMPILER_FLAGS = -Wall -Wextra -pedantic
INCLUDE_PATH = -Iinclude/
SOURCE = src/*.c
TARGET = c_rpg


.DEFAULT_GOAL := build

run: $(TARGET)
	./$(TARGET)

build: src/main.c
	$(COMPILER) $(STANDARD) $(COMPILER_FLAGS) $(INCLUDE_PATH) -o $(TARGET) $(SOURCE)

clean:
	rm $(TARGET)
