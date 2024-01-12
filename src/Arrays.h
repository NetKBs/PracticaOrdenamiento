#ifndef ARRAYS_H
#define ARRAYS_H

#include <array>

class Arrays {
    public:
        static const int SIZE = 30000;
    private:
        
        int unsortedArrays[SIZE];
        int sortedArrays[SIZE];
        int reversedArray[SIZE];

    public:
    
        Arrays();
        void generateArrays();
        
        std::array<int, SIZE> getUnsortedArrayCopy() const;
        std::array<int, SIZE> getSortedArray() const;
        std::array<int, SIZE> getReversedArray() const;

    private:
        void generateUnsortedNonRepeatingArray();
        void generateSortedArray();
        void generateReversedArray();  

};

#endif