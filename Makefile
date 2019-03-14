CC = g++
SRCS = main.cpp xxx.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
.cpp.o:
	$(CC) -o $@ -c $<
clean:
	rm -rf $(OBJS)

