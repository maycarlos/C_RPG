COMPILER = clang
COMPILER_FLAGS = -Wall -Wextra -pedantic
INCLUDE_PATH = -I include/
SOURCE = src/*.c
TARGET = c_rpg


run: build
	./c_rpg

build: src/main.c
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH) -o c_rpg $(SOURCE)

clean: main
	rm main
