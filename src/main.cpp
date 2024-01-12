#include <iostream>
#include "Arrays.h"

using namespace std;
int main() {

    Arrays arraysObjs = Arrays();
    const int SIZE = Arrays::SIZE;
    std::array<int, SIZE> unsortedArray = arraysObjs.getUnsortedArrayCopy();
    std::array<int, SIZE> sortedArray = arraysObjs.getSortedArray();
    std::array<int, SIZE> reversedArray = arraysObjs.getReversedArray();


}