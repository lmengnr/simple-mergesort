CXX=g++
#set exec names to the base name of the directory, and
#replace all spaces with underscores
EXEC:=$(shell basename "`pwd`e" | sed 's/ /_/g')
DEPS:=$(shell find *.h)
SRCS:=$(shell find *.cpp)
OBJS:= $(SRCS:%.cpp=%.o)

all: $(EXEC)

full: clean all

%.o : %.cpp $(DEPS)
	$(CXX) -c -g $<  
	
$(EXEC): $(OBJS)
	$(CXX) -o $@ $^ 
	
clean:
	rm *.o $(EXEC) -f


