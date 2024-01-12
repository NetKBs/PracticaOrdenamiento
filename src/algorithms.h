#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
using namespace std;

// Selection Sort
inline void selectionSort(int arr[], int size, bool sortPartial = false) {
    int n = sortPartial ? min(size, 1000) : size;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            arr[i] ^= arr[min_idx];
            arr[min_idx] ^= arr[i];
            arr[i] ^= arr[min_idx];
        }
    }
}

// Insertion Sort
inline void insertionSort(int arr[], int size, bool sortPartial = false) {
    int n = sortPartial ? min(size, 1000) : size;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
inline void bubbleSort(int arr[], int size, bool sortPartial = false) {
    int n = sortPartial ? min(size, 1000) : size;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Modified Bubble Sort
inline void modifiedBubbleSort(int arr[], int size, bool sortPartial = false) {
    int n = sortPartial ? min(size, 1000) : size;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Quick Sort
inline int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            arr[i] ^= arr[j];
            arr[j] ^= arr[i];
            arr[i] ^= arr[j];
        }
    }
    arr[i + 1] ^= arr[high];
    arr[high] ^= arr[i + 1];
    arr[i + 1] ^= arr[high];
    return i + 1;
}

inline void quickSort(int arr[], int low, int high, bool sortPartial = false) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, sortPartial);
        quickSort(arr, pi + 1, high, sortPartial);
    }
}

#endif