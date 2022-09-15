#include "sortAlgo.h"

sortAlgo::sortAlgo(int numbersOfElements) {
    size = numbersOfElements;
    arr = new int[size];
}

sortAlgo::~sortAlgo() {
    delete[] arr;
}

int sortAlgo::getSize() const {
    return size;
}

void sortAlgo::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void sortAlgo::selectionSort() {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

void sortAlgo::insertionSort() {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortAlgo::printArray() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortAlgo::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortAlgo::randomizeArray() {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % INT32_MAX;
    }
}

bool sortAlgo::isSorted() {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void sortAlgo::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int sortAlgo::partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void sortAlgo::mergeSort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void sortAlgo::merge(int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sortAlgo::heapSort() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

void sortAlgo::heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void sortAlgo::bogoSort() {
    while (!isSorted()) {
        randomizeArray();
    }
}



void sortAlgo::testAlgorithm() {
    cout << "Testing all algorithms..." << "\nNumber of elements : " << size << endl << endl;

    randomizeArray();

    cout << "Bubble sort: ";

    auto start = chrono::high_resolution_clock::now();

    bubbleSort();

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;

    randomizeArray();

    cout << "Selection sort: ";

    start = chrono::high_resolution_clock::now();

    selectionSort();

    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;

    randomizeArray();

    cout << "Insertion sort: ";

    start = chrono::high_resolution_clock::now();

    insertionSort();

    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;

    randomizeArray();

    cout << "Quick sort: ";

    start = chrono::high_resolution_clock::now();

    quickSort(0, size - 1);

    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;

    randomizeArray();

    cout << "Merge sort: ";

    start = chrono::high_resolution_clock::now();

    mergeSort(0, size - 1);

    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;

    randomizeArray();

    cout << "Heap sort: ";

    start = chrono::high_resolution_clock::now();

    heapSort();

    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << isSorted() << endl;
}