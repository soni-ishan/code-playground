CXX = g++

CXXFLAGS = -Wall -std=c++17

TARGET = assign2isx183.exe

OBJ = heap.o run.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

run.o: run.cpp heap.h
	$(CXX) $(CXXFLAGS) -c run.cpp
	
clean:
	rm -f $(OBJ) $(TARGET)