# Makefile for C Source Code Analyzer
# Usage: make (to compile) or make clean (to remove compiled files)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = analyzer
SOURCES = main.c symbol_table.c analyzer.c utils.c
OBJECTS = $(SOURCES:.c=.o)

# Default target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✅ Compilation successful! Run './analyzer' (Linux/Mac) or 'analyzer.exe' (Windows)"

# Compile individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	del *.o $(TARGET).exe 2>nul || rm -f *.o $(TARGET)
	@echo "🧹 Cleaned compiled files"

# Show help
help:
	@echo "Available targets:"
	@echo "  make        - Compile the analyzer"
	@echo "  make clean  - Remove compiled files"
	@echo "  make help   - Show this help message"

.PHONY: clean help
