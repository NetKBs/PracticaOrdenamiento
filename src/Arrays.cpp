#include "Arrays.h"
#include <random>

Arrays::Arrays() { generateArrays(); }

void Arrays::generateArrays() {
  generateUnsortedNonRepeatingArray();
  generateSortedArray();
  generateReversedArray();
}

void Arrays::generateUnsortedNonRepeatingArray() {

  for (int i = 0; i < SIZE; i++) {
    unsortedArrays[i] = i + 1;
  }

  std::random_device rd;
  std::mt19937 gen(rd());

  for (int i = SIZE - 1; i > 0; i--) {
    std::uniform_int_distribution<int> dis(0, i);
    int j = dis(gen);
    std::swap(unsortedArrays[i], unsortedArrays[j]);
  }
}

void Arrays::generateSortedArray() {
  for (int i = 0; i < SIZE; i++) {
    sortedArrays[i] = i + 1;
  }
}

void Arrays::generateReversedArray() {
  for (int i = 0; i < SIZE; i++) {
    reversedArray[i] = SIZE - i;
  }
}

std::array<int, Arrays::SIZE> Arrays::getUnsortedArrayCopy() const {
  std::array<int, SIZE> copy;
  for (int i = 0; i < SIZE; i++) {
    copy[i] = unsortedArrays[i];
  }
  return copy;
}
std::array<int, Arrays::SIZE> Arrays::getSortedArray() const {
  std::array<int, SIZE> copy;
  for (int i = 0; i < SIZE; i++) {
    copy[i] = sortedArrays[i];
  }
  return copy;
}
std::array<int, Arrays::SIZE> Arrays::getReversedArray() const {
  std::array<int, SIZE> copy;
  for (int i = 0; i < SIZE; i++) {
    copy[i] = reversedArray[i];
  }
  return copy;
}
