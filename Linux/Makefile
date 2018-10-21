CC = g++

EXE = dictionary

HDRS = dict.h

SRCS = main.cpp dict.cpp

OBJS = $(SRCS:.cpp=.o)

$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS)

$(OBJS): $(HDRS) Makefile

clean:
	rm -f *.o
