CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lstdc++fs

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.exe)
EXECUTABLE = $(BIN_DIR)/ tarea5

.PHONY: all clean

all: build run

build: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(BIN_DIR)\*.exe
