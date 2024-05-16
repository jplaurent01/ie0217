#Define el compilador
CXX = g++
#Define las banderas del compilador
CXXFLAGS = -Wall -std=c++11
#Define las banderas del enlazador para enlazar la biblioteca
LDFLAGS = -lstdc++fs

##Directorio codigo fuente
SRC_DIR = src
#Directorio donde se colocan binarios
BIN_DIR = bin

#Lista de archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
#Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.exe)
#Nombre del ejecutable final
EXECUTABLE = $(BIN_DIR)/ tarea5

#Reglas
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
