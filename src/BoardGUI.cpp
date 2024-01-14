#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "AlgorithmHandler.h"
#include "BoardGUI.h"

// Función consolidada para mostrar la tabla
void llenarYMostrarTabla(const AlgorithmHandler& handler, const std::vector<std::string>& titulosFila, const std::vector<std::string>& titulosColumna, const std::string& tipoDato) {
    // Configurar el formato de salida para los tiempos
    std::cout << std::fixed << std::setprecision(7);

    // Imprimir títulos de las columnas en la parte superior
    std::cout << std::setw(15) << "" << "\t";  // Espacio para la esquina superior izquierda
    for (int j = 0; j < titulosFila.size(); ++j) {
        std::cout << std::setw(15) << titulosFila[j] << "\t";
    }
    std::cout << std::endl;

    // Imprimir títulos de las filas en el lado izquierdo y los valores de la tabla
    for (int i = 0; i < titulosColumna.size(); ++i) {
        // Imprimir títulos de las filas en el lado izquierdo
        std::cout << std::setw(15) << titulosColumna[i] << "\t";

        for (int j = 0; j < titulosFila.size(); ++j) {
            // Seleccionar el tipo de dato correspondiente
            if (tipoDato == "tiempo") {
                // Imprimir tiempos como double
                std::cout << std::setw(15) << handler.results[i][j].data.time << "\t";
            } else if (tipoDato == "comparaciones") {
                // Imprimir comparaciones como int
                std::cout << std::setw(15) << handler.results[i][j].data.comparisons << "\t";
            } else if (tipoDato == "intercambios") {
                // Imprimir intercambios como int
                std::cout << std::setw(15) << handler.results[i][j].data.swaps << "\t";
            } else {
                // Manejar un tipo de dato no válido
                std::cerr << "Error: Tipo de dato no válido." << std::endl;
                return;
            }
        }
        std::cout << std::endl;
    }
}


// Función principal que maneja el menú
void BoardGUI::mostrarMenu(const AlgorithmHandler& handler, const std::vector<std::string>& titulosFila, const std::vector<std::string>& titulosColumna) {
    int opcion;

    do {
        // Mostrar el menú
        std::cout << "\n\tB I E N V E N I D O   A L   M E N U\n";
        std::cout << "1. Mostrar Resultados por tiempos\n";
        std::cout << "2. Mostrar Resultados por comparaciones\n";
        std::cout << "3. Mostrar Resultados por intercambios\n";
        std::cout << "4. Mostrar Resultados por Ordenamiento Parcial\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // Realizar la acción correspondiente según la opción seleccionada
        switch (opcion) {
            case 1:
                llenarYMostrarTabla(handler, titulosFila, titulosColumna, "tiempo");
                break;
                system("cls");  
            case 2:
                llenarYMostrarTabla(handler, titulosFila, titulosColumna, "comparaciones");
                break;
            case 3:
                llenarYMostrarTabla(handler, titulosFila, titulosColumna, "intercambios");
                break;
            case 4:

                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Inténtelo de nuevo.\n";
        }

            
  
    } while (opcion != 0);
}

