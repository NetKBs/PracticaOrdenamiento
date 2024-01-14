
#include <iostream>
#include "AlgorithmHandler.h"
#include "BoardGUI.h"
#include <vector>
#include <iomanip>
#include <algorithm>

 
using namespace std;


int main() {

    // Definir títulos para la primera fila (en la parte superior)
    std::vector<std::string> titulosFila = {"Desordenado", "Ordenado", "Invertido"};

    // Definir títulos para la primera columna (en el lado izquierdo)
    std::vector<std::string> titulosColumna = {"Seleccion", "Insercion", "Burbuja", "B-Modificado", "Shell Sort", "Quick Sort"};

    // Crear el objeto AlgorithmHandler y ejecutar los algoritmos
    AlgorithmHandler handler;
    handler.runAllAlgorithms();
    //handler.runAllAlgorithmsPartially();
    
    // Crear objeto BoardGUI para mostrar el menu principal
    BoardGUI GUI;
    GUI.mostrarMenu(handler, titulosFila, titulosColumna);
 
    return 0;
}

