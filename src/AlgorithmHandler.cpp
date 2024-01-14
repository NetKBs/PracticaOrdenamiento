#include "AlgorithmHandler.h"
#include "algorithms.h"
#include <chrono>
#include <utility>
#include <vector>

AlgorithmHandler::AlgorithmHandler() {

  unsortedArray = arraysObjs.getUnsortedArrayCopy();
  sortedArray = arraysObjs.getSortedArray();
  reversedArray = arraysObjs.getReversedArray();
  arraysToTest = {unsortedArray, sortedArray, reversedArray};
}

void AlgorithmHandler::runAllAlgorithms() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {

      std::pair<int, int> count;
      std::array<int, ARR_SIZE> arr;
      std::copy(arraysToTest[j].begin(), arraysToTest[j].end(), arr.begin());

      auto start = std::chrono::high_resolution_clock::now();
      switch (i) {
      case 0:
        count = selectionSort(arr.data(), ARR_SIZE);
        break;
      case 1:
        count = insertionSort(arr.data(), ARR_SIZE);
        break;
      case 2:
        count = bubbleSort(arr.data(), ARR_SIZE);
        break;
      case 3:
        count = modifiedBubbleSort(arr.data(), ARR_SIZE);
        break;
      case 4:
        count = shellSort(arr.data(), ARR_SIZE);
        break;
      case 5:
        count = quickSort(arr.data(), 0, ARR_SIZE - 1);
        break;
      }
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> duration = end - start;

      results[i][j].data.swaps = count.first;
      results[i][j].data.comparisons = count.second;
      results[i][j].data.time = duration.count();
      std::cout << "Algoritmo " << getAlgorithmName(Algorithms(i)) << " Array "
                << getArrayTypeName(ArraysTypes(j)) << " terminado"
                << std::endl;
      
    }
  }
}

void AlgorithmHandler::runAllAlgorithmsPartially() {
  for (int i = 0; i < 6; i++) {
    std::pair<int, int> count;
    std::array<int, ARR_SIZE> arr;
    std::copy(unsortedArray.begin(), unsortedArray.end(), arr.begin());

    auto start = std::chrono::high_resolution_clock::now();
    switch (i) {
    case 0:
      count = selectionSort(arr.data(), ARR_SIZE, true);
      break;
    case 1:
      count = insertionSort(arr.data(), ARR_SIZE, true);
      break;
    case 2:
      count = bubbleSort(arr.data(), ARR_SIZE, true);
      break;
    case 3:
      count = modifiedBubbleSort(arr.data(), ARR_SIZE, true);
      break;
    case 4:
      count = shellSort(arr.data(), ARR_SIZE, true);
      break;
    case 5:
      count = quickSort(arr.data(), 0, ARR_SIZE - 1, true);
      break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    resultsPartial[i].data.swaps = count.first;
    resultsPartial[i].data.comparisons = count.second;
    resultsPartial[i].data.time = duration.count();
    std::cout << "Algoritmo " << getAlgorithmName(Algorithms(i)) << " Array UNSORTED"
              << " Parcialmente" << " terminado" << std::endl;
  
  }
}

void AlgorithmHandler::sortBestResults() {
    
    // Array of algorithm names for quick access based on index
    const std::array<std::string, NUM_ALGORITHMS> algorithmNames = {
        "Seleccion", "Insercion", "Burbuja", "B-Modificado", "Shell Sort", "Quick Sort"
    };

    // Fill the results arrays
    for (int i = 0; i < NUM_ALGORITHMS; ++i) {
        const std::string& name = algorithmNames[i];
        for (int j = 0; j < NUM_ARRAY_TYPES; ++j) {
            timeResults[j][i] = {name, results[i][j].data.time};
            compResults[j][i] = {name, results[i][j].data.comparisons};
            swapsResults[j][i] = {name, results[i][j].data.swaps};
        }
    }

   // Sort
   for (int i = 0; i < NUM_ARRAY_TYPES; i++) {
    quickSortAlternativeForDoubles(timeResults[i], 0, 6-1);
    quickSortAlternativeForInts(swapsResults[i], 0, 6-1);
    quickSortAlternativeForInts(compResults[i], 0, 6-1);
   }

}