# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Executable name
TARGET = $(BIN_DIR)/tic-tac-toe

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRCS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $@

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all clean
