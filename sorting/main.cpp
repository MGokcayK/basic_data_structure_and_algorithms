#include "sorting.h"

void main()
{
    srand(time(0));  // Initialize random number generator.

    vector<int> vectorForOrder; // Initialize vector to store value.

    for (int i = 0; i < 20; i++)
    {
        int value = (rand() % 100) + 1; // create random number between 1-100
        vectorForOrder.push_back(value); // append number to vector
    }

    cout << " Unsorted Vector " << endl;
    printVector(vectorForOrder); // print unsorted vector

    selectionSort(vectorForOrder, true); // call sorting method

    cout << endl << " Sorted Vector " << endl;
    printVector(vectorForOrder); // print sorted method
    
}