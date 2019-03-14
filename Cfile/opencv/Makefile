CXX      = g++
CFLAGS   = -Wall 
LDFLAGS  = `pkg-config --cflags --libs opencv`
SRCS = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SRCS))
all:$(TARGETS)
$(TARGETS):$(SRCS)
	$(CXX) -o $@ $< $(LDFLAGS) $(CFLAGS)
clean:
	-rm -rf $(TARGETS) *~ .*swp
#.PHONY: clean all
