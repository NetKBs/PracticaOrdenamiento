// BoardGUI.h

#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "AlgorithmHandler.h"
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
const std::string SO = "WIN";
#elif __linux__
const std::string SO = "UNIX";
#endif

inline void clearScreen() {
    if (SO == "WIN") {
        system("cls");
    } else if (SO == "UNIX") {
        system("clear");
    }
}

inline void waitForInput() {
    std::cin.ignore();
    std::cin.get(); 
}

class BoardGUI {
public:
    void mostrarMenu(const AlgorithmHandler& handler, const std::vector<std::string>& titulosFila, const std::vector<std::string>& titulosColumna);
    
}; 

#endif // BOARDGUI_H
