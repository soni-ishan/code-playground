CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = assign3isx183.exe
SOURCE = assign3isx183.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)