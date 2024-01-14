#include "BoardGUI.h"
#include "AlgorithmHandler.h"
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>

void llenarYMostrarTablaOrdenada(const AlgorithmHandler &handler,
                                 const std::string &tipoDato) {
  std::cout << std::fixed
            << std::setprecision(7); // Set precision for floating point output.

  clearScreen();
  std::string arrayType = "";

  for (int i = 0; i < NUM_ARRAY_TYPES; i++) {

    switch (i) {
    case 0:
      arrayType = "Desordenado";
      break;
    case 1:
      arrayType = "Ordenado";
      break;
    case 2:
      arrayType = "Invertido";
      break;
    }

    if (tipoDato == "tiempo") {

      std::cout << "Array " << arrayType << std::endl;
      for (int j = 0; j < NUM_ALGORITHMS; ++j) {
        std::cout << j + 1 << "-" << handler.timeResults[i][j].name << " - "
                  << handler.timeResults[i][j].d_data << std::endl;
      }
      std::cout << std::endl;

    } else if (tipoDato == "comparaciones") {

      std::cout << "Array " << arrayType << std::endl;
      for (int j = 0; j < NUM_ALGORITHMS; ++j) {
        std::cout << j + 1 << "-" << handler.swapsResults[i][j].name << " - "
                  << handler.swapsResults[i][j].i_data << std::endl;
      }
      std::cout << std::endl;

    } else if (tipoDato == "intermcabio") {

      std::cout << "Array " << arrayType << std::endl;
      for (int j = 0; j < NUM_ALGORITHMS; ++j) {
        std::cout << j + 1 << "-" << handler.compResults[i][j].name << " - "
                  << handler.compResults[i][j].i_data << std::endl;
      }
      std::cout << std::endl;
    }
  }
  std::cout << "Presiona Enter para continuar...";
  waitForInput();
}

// Displays a table with headers and data based on the specified data type.
void llenarYMostrarTabla(const AlgorithmHandler &handler,
                         const std::vector<std::string> &titulosFila,
                         const std::vector<std::string> &titulosColumna,
                         const std::string &tipoDato) {
  std::cout << std::fixed
            << std::setprecision(7); // Set precision for floating point output.

  clearScreen();
  // Print column headers
  std::cout << std::setw(15) << ""
            << "\t";
  for (const auto &titulo : titulosFila) {
    std::cout << std::setw(15) << titulo << "\t";
  }
  std::cout << std::endl;

  // Print row headers and table data
  for (size_t i = 0; i < titulosColumna.size(); ++i) {
    std::cout << std::setw(15) << titulosColumna[i] << "\t";

    for (size_t j = 0; j < titulosFila.size(); ++j) {
      // Output data based on the specified type
      if (tipoDato == "tiempo") {
        std::cout << std::setw(15) << handler.results[i][j].data.time << "\t";
      } else if (tipoDato == "comparaciones") {
        std::cout << std::setw(15) << handler.results[i][j].data.comparisons
                  << "\t";
      } else if (tipoDato == "intercambios") {
        std::cout << std::setw(15) << handler.results[i][j].data.swaps << "\t";
      } else {
        std::cerr << "Error: Invalid data type." << std::endl;
        return;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "Presiona Enter para continuar...";
  waitForInput();
}

void llenarYMostrarTablaParcial(const AlgorithmHandler &handler,
                                const std::vector<std::string> &titulosColumna,
                                const std::string &tipoDato) {
  std::cout << std::fixed
            << std::setprecision(7); // Set precision for floating point output.

  clearScreen();
  // Print column headers
  std::cout << std::setw(15) << ""
            << "\t";
  std::cout << std::setw(15) << "Desordenado"
            << "\t";
  std::cout << std::endl;

  // Print row headers and table data
  for (size_t i = 0; i < titulosColumna.size(); ++i) {
    std::cout << std::setw(15) << titulosColumna[i] << "\t";

    if (tipoDato == "tiempo") {
      std::cout << std::setw(15) << handler.resultsPartial[i].data.time << "\t";
    } else if (tipoDato == "comparaciones") {
      std::cout << std::setw(15) << handler.resultsPartial[i].data.comparisons
                << "\t";
    } else if (tipoDato == "intercambios") {
      std::cout << std::setw(15) << handler.resultsPartial[i].data.swaps
                << "\t";
    } else {
      std::cerr << "Error: Invalid data type." << std::endl;
      return;
    }

    std::cout << std::endl;
  }
  std::cout << "Presiona Enter para continuar...";
  waitForInput();
}

// Función principal que maneja el menú
void BoardGUI::mostrarMenu(const AlgorithmHandler &handler,
                           const std::vector<std::string> &titulosFila,
                           const std::vector<std::string> &titulosColumna) {
  int opcion;

  do {
    clearScreen();
    // Mostrar el menú
    std::cout << "\n\tB I E N V E N I D O   A L   M E N U\n";
    std::cout << "1. Mostrar Resultados por tiempos\n";
    std::cout << "2. Mostrar Resultados por comparaciones\n";
    std::cout << "3. Mostrar Resultados por intercambios\n";
    std::cout << "4. Mostrar Resultados Parciales Por Tiempo\n";
    std::cout << "5. Mostrar Resultados Parciales Por Comparaciones\n";
    std::cout << "6. Mostrar Resultados Parciales Por Intercambios\n";
    std::cout << "7. Mostrar Mejores Tiempos\n";
    std::cout << "8. Mostrar Mejores Comparaciones\n";
    std::cout << "9. Mostrar Mejores Intercambios\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    // Realizar la acción correspondiente según la opción seleccionada
    switch (opcion) {
    case 1:
      llenarYMostrarTabla(handler, titulosFila, titulosColumna, "tiempo");
      break;

    case 2:
      llenarYMostrarTabla(handler, titulosFila, titulosColumna,
                          "comparaciones");
      break;
    case 3:
      llenarYMostrarTabla(handler, titulosFila, titulosColumna, "intercambios");
      break;
    case 4:
      llenarYMostrarTablaParcial(handler, titulosColumna, "tiempo");
      break;
    case 5:
      llenarYMostrarTablaParcial(handler, titulosColumna, "comparaciones");
      break;
    case 6:
      llenarYMostrarTablaParcial(handler, titulosColumna, "intercambios");
      break;
    case 7:
        llenarYMostrarTablaOrdenada(handler, "tiempo");
        break;
    case 8:
        llenarYMostrarTablaOrdenada(handler, "comparaciones");
    case 9:
        llenarYMostrarTablaOrdenada(handler, "intercambios");
    case 0:
      std::cout << "Saliendo del programa...\n";
      break;
    default:
      std::cout << "Opción no válida. Inténtelo de nuevo.\n";
    }

  } while (opcion != 0);
}
