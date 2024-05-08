# Nombre del programa de salida
TARGET = gestion_biblioteca.exe

#Objetivos predeterminados
all: $(TARGET)

# Compilador cpp
CXX = g++

# Opciones de compilacion version compilador c++11
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SOURCES = libro.cpp biblioteca.cpp main.cpp 

# Lista de archivos de objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar los archivos fuente a partir archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados
.PHONY: clean	
clean:
	del $(TARGET) $(OBJECTS)
