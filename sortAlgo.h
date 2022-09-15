#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#ifndef SORTALGO_SORTALGO_H
#define SORTALGO_SORTALGO_H


class sortAlgo {
    private:
        int *arr;
        int size;

public:
    sortAlgo(int numbersOfElements);
    ~sortAlgo();

    int getSize() const;

    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void printArray();
    void swap(int *a, int *b);
    void randomizeArray();
    bool isSorted();

    void quickSort(int low, int high);
    int partition(int low, int high);

    void mergeSort(int low, int high);
    void merge(int low, int mid, int high);

    void heapSort();
    void heapify(int n, int i);

    void bogoSort();

    void testAlgorithm();
};


#endif //SORTALGO_SORTALGO_H
