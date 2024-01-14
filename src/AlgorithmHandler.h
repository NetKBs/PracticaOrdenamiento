#ifndef ALGORITHM_HANDLER_H
#define ALGORITHM_HANDLER_H

#include "Arrays.h"
#include <string>


const int NUM_ALGORITHMS = 6;
const int NUM_ARRAY_TYPES = 3;
const int NUM_DATA = 3;

struct Data {
    int swaps;
    int comparisons;
    double time;
};

struct Result{
    Data data;
};

struct NameDouble {
    std::string name;
    double d_data;
};

struct NameInt {
    std::string name;
    int i_data;
};


enum Algorithms {
    SELECTION_SORT,
    INSERTION_SORT,
    BUBBLE_SORT,
    MODIFIED_BUBBLE_SORT,
    SHELL_SORT,
    QUICK_SORT
};
enum ArraysTypes {
    UNSORTED,
    SORTED,
    REVERSED
};

inline std::string getAlgorithmName(Algorithms algorithm) {
    switch (algorithm) {
        case SELECTION_SORT:
            return "SELECTION_SORT";
        case INSERTION_SORT:
            return "INSERTION_SORT";
        case BUBBLE_SORT:
            return "BUBBLE_SORT";
        case MODIFIED_BUBBLE_SORT:
            return "MODIFIED_BUBBLE_SORT";
        case SHELL_SORT:
            return "SHELL_SORT";
        case QUICK_SORT:
            return "QUICK_SORT";
        default:
            return "UNKNOWN";
    }
}

inline std::string getArrayTypeName(ArraysTypes arrayType) {
    switch (arrayType) {
        case UNSORTED:
            return "UNSORTED";
        case SORTED:
            return "SORTED";
        case REVERSED:
            return "REVERSED";
        default:
            return "UNKNOWN";
    }
}

class AlgorithmHandler {

    public:
        Result results[NUM_ALGORITHMS][NUM_ARRAY_TYPES];
        Result resultsPartial[NUM_ALGORITHMS]; // Only Unsorted Array is used
        // Arrays to hold the results for different array states
        NameDouble timeResults[NUM_ARRAY_TYPES][NUM_ALGORITHMS];
        NameInt swapsResults[NUM_ARRAY_TYPES][NUM_ALGORITHMS];
        NameInt compResults[NUM_ARRAY_TYPES][NUM_ALGORITHMS];
        
    private:
        Arrays arraysObjs = Arrays();
        static const int ARR_SIZE = Arrays::SIZE;

        std::array<int, ARR_SIZE> unsortedArray;
        std::array<int, ARR_SIZE> sortedArray;
        std::array<int, ARR_SIZE> reversedArray;
        std::array<std::array<int, ARR_SIZE>, 3> arraysToTest;

 
    public:
        AlgorithmHandler();

        void runAllAlgorithms();
        void runAllAlgorithmsPartially();
        void sortBestResults();
};


#endif