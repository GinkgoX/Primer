CC = g++
SRCS = main.cpp student.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
.cpp.o:
	$(CC) -o $@ -c $<
clean:
	rm -rf $(OBJS)

