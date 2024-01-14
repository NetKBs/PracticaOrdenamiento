#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "AlgorithmHandler.h"
#include <iostream>
using namespace std;

// Selection Sort
inline std::pair<int, int> selectionSort(int arr[], int size, bool sortPartial = false) {
  int size_ = sortPartial ? 1000 : size;
  int swaps = 0;
  int comparisons = 0;

  for (int i = 0; i < size_ - 1; i++) {
    int minIndex = i;
    int minValue = arr[i];

    for (int j = i + 1; j < size_; j++) {
      comparisons++; 
      if (arr[j] < minValue) {
        minIndex = j;
        minValue = arr[j];
      }
    }

    if (minIndex != i) {
      swaps++; // Counting swaps
      arr[minIndex] = arr[i];
      arr[i] = minValue;
      
    }

  }

  return {swaps, comparisons};
}


inline std::pair<int, int> insertionSort(int arr[], int size, bool sortPartial = false) {
  int size_ = sortPartial ? 1000 : size;
  int swaps = 0, comparisons = 0;

  for (int i = 1; i < size_; i++) {
    int value = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > value) {
      arr[j] = arr[j - 1];
      j--;
      swaps++;
      comparisons++;
    }
    arr[j] = value;
  }
  
  return {swaps, comparisons};
}

inline std::pair<int, int> bubbleSort(int arr[], int size, bool sortPartial = false) {
  int size_ = sortPartial ? 1000 : size;
  int swaps = 0, comparisons = 0;

  for (int i = 0; i < size_ - 1; i++) {
    for (int j = 0; j < size_ - i - 1; j++) {
        comparisons++;

      if (arr[j] > arr[j + 1]) {
        swaps++;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  return {swaps, comparisons};
}

inline std::pair<int, int> modifiedBubbleSort(int arr[], int size, bool sortPartial = false) {
  int size_ = sortPartial ? 1000 : size;
  bool swapped = false;
  int swaps = 0, comparisons = 0;

  for (int i = 0; i < size_ - 1; i++) {
    swapped = false;
    for (int j = 0; j < size_ - i - 1; j++) {
      comparisons++; 

      if (arr[j] > arr[j + 1]) {
        swaps++;

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

  return {swaps, comparisons};
}


inline std::pair<int, int> shellSort(int arr[], int size, bool sortPartial = false) {
  int size_ = sortPartial ? 1000 : size;
  int swaps = 0;
  int comparisons = 0;

  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size_; i++) {
      for (int j = i; j >= gap; j -= gap) {
        comparisons++;

        if (arr[j - gap] > arr[j]) {
          swaps++;
          std::swap(arr[j], arr[j - gap]);
        }
      }
    }
  }

  return {swaps, comparisons};
}



// Improved partitioning function for QuickSort algorithm
int partition(int arr[], int low, int high, int& swaps, int& comparisons) {
  // Choosing median of three as pivot to handle sorted arrays more efficiently
  int mid = low + (high - low) / 2;
  if (arr[mid] < arr[low])
      std::swap(arr[low], arr[mid]), swaps++;
  if (arr[high] < arr[low])
      std::swap(arr[low], arr[high]), swaps++;
  if (arr[mid] < arr[high])
      std::swap(arr[mid], arr[high]), swaps++;
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    comparisons++;
    if (arr[j] <= pivot) {
      i++;
      if (i != j) {
        std::swap(arr[i], arr[j]);
        swaps++;
      }
    }
  }
  std::swap(arr[i + 1], arr[high]);
  swaps++;

  return (i + 1);
}

// QuickSort algorithm with improved performance on sorted arrays
std::pair<int, int> quickSort(int arr[], int low, int high, bool sortPartial = false) {
  int swaps = 0, comparisons = 0;

  if (sortPartial) {
    // Limit the range to the partial array size
    high = std::min(high, low + 999);
  }

  if (low < high) {
    int pi = partition(arr, low, high, swaps, comparisons);

    std::pair<int, int> leftCounters = quickSort(arr, low, pi - 1, sortPartial);
    std::pair<int, int> rightCounters = quickSort(arr, pi + 1, high, sortPartial);

    swaps += leftCounters.first + rightCounters.first;
    comparisons += leftCounters.second + rightCounters.second;
  }

  return {swaps, comparisons};
}

/*

int partitionStruct(Lista arr[], int low, int high) {
    Lista& pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].tiempo <= pivot.tiempo) {
            i++;
            if (i != j) {
                swapStruct(arr[i], arr[j]);
            }
        }
    }
    swapStruct(arr[i + 1], arr[high]);
    return i + 1;
}

void ordenamientoQuickSortStruct(Lista arr[], int low, int high) {
    if (low < high) {
        int pi = partitionStruct(arr, low, high);
        ordenamientoQuickSortStruct(arr, low, pi - 1);
        ordenamientoQuickSortStruct(arr, pi + 1, high);
    }
}


*/

int partitionAlternativeForDoubles(NameDouble arr[], int low, int high) {
    NameDouble& pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].d_data <= pivot.d_data) {
            i++;
            if (i != j) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


inline void quickSortAlternativeForDoubles(NameDouble arr[], int low, int high) {
  if (low < high) {
        int pi = partitionAlternativeForDoubles(arr, low, high);
        quickSortAlternativeForDoubles(arr, low, pi - 1);
        quickSortAlternativeForDoubles(arr, pi + 1, high);
    }
}

int partitionAlternativeForInts(NameInt arr[], int low, int high) {
    NameInt& pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].i_data <= pivot.i_data) {
            i++;
            if (i != j) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


inline void quickSortAlternativeForInts(NameInt arr[], int low, int high) {
  if (low < high) {
        int pi = partitionAlternativeForInts(arr, low, high);
         quickSortAlternativeForInts(arr, low, pi - 1);
        quickSortAlternativeForInts(arr, pi + 1, high);
    }
}

#endif