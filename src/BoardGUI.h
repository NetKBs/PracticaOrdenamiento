// BoardGUI.h

#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "AlgorithmHandler.h"
#include <vector>
#include <string>

class BoardGUI {
public:
    void mostrarMenu(const AlgorithmHandler& handler, const std::vector<std::string>& titulosFila, const std::vector<std::string>& titulosColumna);
    // Otros miembros y funciones de la clase BoardGUI, si es necesario
}; 

#endif // BOARDGUI_H
