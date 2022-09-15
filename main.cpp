#include <iostream>
#include "sortAlgo.h"


int main() {

    bool test = true;

    sortAlgo sort((test ? 100 : INT32_MAX));

    //sort.testAlgorithm();

    sort.randomizeArray();

    auto start = high_resolution_clock::now();

    //sort.quickSort(0, sort.getSize() - 1);

    sort.bogoSort();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Quick sort took " << duration.count() << " microseconds / " << duration.count() / 1000000 << " seconds  || array sorted : " << sort.isSorted() << endl;

    return 0;
}
