CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lGL -lGLU -lglfw3 -lm -lX11 -lXxf86vm -lXrandr -lpthread
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

SRC_DIR = src
BUILD_DIR = build
TARGET = main

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

.PHONY: run memcheck clean
run: $(TARGET)
	./$(TARGET)

memcheck: $(TARGET)
	valgrind $(VALGRIND_FLAGS) ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
