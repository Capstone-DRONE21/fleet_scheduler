CXX := clang++
CPPFLAGS += -Iinclude
CXXFLAGS += -std=c++17 -Wall -Wextra -pedantic

SOURCES := src/main.cpp src/scheduler.cpp
TARGET := build/fleet_scheduler

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) include/fleet_scheduler/scheduler.hpp
	mkdir -p build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(TARGET)
