#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Forward declaration of the partition function for deterministic quicksort
int deterministicPartition(std::vector<int> &numbers, int left, int right);

// Function to perform deterministic quicksort
void deterministicQuickSort(std::vector<int> &numbers, int left, int right) {
    if (left < right) {
        int partitionIndex = deterministicPartition(numbers, left, right);

        deterministicQuickSort(numbers, left, partitionIndex - 1);
        deterministicQuickSort(numbers, partitionIndex + 1, right);
    }
}

// Function to perform randomized quicksort
void randomizedQuickSort(std::vector<int> &numbers, int left, int right) {
    if (left < right) {
        int pivotIndex = left + rand() % (right - left + 1);

        std::swap(numbers[pivotIndex], numbers[right]);
        int pivot = numbers[right];
        int partitionIndex = deterministicPartition(numbers, left, right);

        randomizedQuickSort(numbers, left, partitionIndex - 1);
        randomizedQuickSort(numbers, partitionIndex + 1, right);
    }
}

// Function to partition the array for quicksort in deterministic quicksort
int deterministicPartition(std::vector<int> &numbers, int left, int right) {
    int pivot = numbers[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (numbers[i] < pivot) {
            i++;
        }
        while (numbers[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(numbers[i], numbers[j]);
            i++;
            j--;
        }
    }

    return i;
}

int main() {
    srand(time(0)); // Seed the random number generator

    std::vector<int> numbers(10000);
    for (int i = 0; i < numbers.size(); ++i) {
        numbers[i] = rand();
    }

    std::vector<int> deterministicSort = numbers; // Create a copy for deterministic sort
    std::vector<int> randomizedSort = numbers; // Create a copy for randomized sort

    clock_t deterministicTime = clock();
    deterministicQuickSort(deterministicSort, 0, deterministicSort.size() - 1);
    clock_t deterministicTimeEnd = clock();

    clock_t randomizedTime = clock();
    randomizedQuickSort(randomizedSort, 0, randomizedSort.size() - 1);
    clock_t randomizedTimeEnd = clock();

    std::cout << "Deterministic quick sort time: " << (double)(deterministicTimeEnd - deterministicTime) / CLOCKS_PER_SEC << " seconds\n";
    std::cout << "Randomized quick sort time: " << (double)(randomizedTimeEnd - randomizedTime) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
