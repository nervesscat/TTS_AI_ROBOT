CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

SRCS = main.cpp voice.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = output

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)