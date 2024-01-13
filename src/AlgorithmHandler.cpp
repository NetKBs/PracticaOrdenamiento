#include "AlgorithmHandler.h"
#include "algorithms.h"
#include <chrono>
#include <utility>

AlgorithmHandler::AlgorithmHandler() {

  unsortedArray = arraysObjs.getUnsortedArrayCopy();
 sortedArray = arraysObjs.getSortedArray();
  reversedArray = arraysObjs.getReversedArray();
  arraysToTest = {unsortedArray, sortedArray, reversedArray};

}


void AlgorithmHandler::runAllAlgorithms() {
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){

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
                    count = quickSort(arr.data(), 0, ARR_SIZE-1);
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start; 

            results [i][j].data.swaps = count.first;
            results [i][j].data.comparisons = count.second;
            results [i][j].data.time = duration.count();
            std::cout << "Algoritmo " << getAlgorithmName(Algorithms(i)) << " Array " << getArrayTypeName(ArraysTypes(j)) << " terminado" << std::endl;
           // std::cout << "Tiempo: " << duration.count() << " Swaps: " << count.first << " Comparisons: " << count.second << std::endl << "" << std::endl;
            
        }
    }
}



