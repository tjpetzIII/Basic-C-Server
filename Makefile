# Makefile for basic C web server

CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -g -Iinclude
TARGET  = webserver
SRCDIR  = src
SRCS    = $(SRCDIR)/main.c \
          $(SRCDIR)/server.c \
          $(SRCDIR)/request.c \
          $(SRCDIR)/response.c \
          $(SRCDIR)/utils.c
OBJS    = $(SRCS:.c=.o)

# --------------------------------------------------------------------------
# Default target: build the server binary
# --------------------------------------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file into a .o object file
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------------------------
# Run the server (default port 8080)
# --------------------------------------------------------------------------
run: all
	./$(TARGET)

# --------------------------------------------------------------------------
# Clean build artifacts
# --------------------------------------------------------------------------
clean:
	rm -f $(OBJS) $(TARGET)

# --------------------------------------------------------------------------
# Rebuild from scratch
# --------------------------------------------------------------------------
rebuild: clean all

# --------------------------------------------------------------------------
# Check code with address/undefined-behavior sanitizers (great for learning)
# --------------------------------------------------------------------------
debug: CFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
debug: rebuild

# --------------------------------------------------------------------------
# Static analysis (requires cppcheck to be installed)
# --------------------------------------------------------------------------
lint:
	cppcheck --enable=all --suppress=missingIncludeSystem -Iinclude $(SRCS)

.PHONY: all run clean rebuild debug lint
