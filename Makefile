CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJS = examheap.o heap.o
TARGET = examheap

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
	rm -f $(OBJS) $(TARGET)