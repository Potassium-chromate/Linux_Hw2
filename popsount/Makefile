CC = gcc
TARGET = hamming_test
SRC = $(TARGET).c

$(TARGET): $(SRC)
	$(CC) -o $@ $<

fast:
	./$(TARGET) fast

slow:
	./$(TARGET) slow

clean:
	rm -f $(TARGET)

