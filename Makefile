TARGET_EXEC = minecraft2d

CC = gcc

BUILD_DIR = build
SRC_DIR = src

SRCS := $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CFLAGS = -Wall -O3
LFLAGS = -lSDL2
IFLAGS = -I src/

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@echo "Generating target: $(TARGET_EXEC)"
	@$(CC) -o $@ $^ $(LFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	@$(MKDIR_P) $(dir $@)
	@echo "Compiling $^"
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

MKDIR_P = mkdir -p
