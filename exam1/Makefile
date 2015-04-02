.PHONY : clean

CXX = g++
CPPFLAGS = -std=c++11 -O2

TARGET = a.out
SOURCE = orienteering.cpp map.cpp

$(TARGET): $(SOURCE)
	$(CXX) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
