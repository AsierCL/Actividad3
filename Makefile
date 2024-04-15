CC = gcc
TARGET = programa
SRCDIR = .

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@


clean:
	rm -f $(OBJECTS)

cleanall: clean
	rm -f  $(TARGET)