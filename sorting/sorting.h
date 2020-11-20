#pragma once
/*
*	@Author : Mehmet Gokcay Kabatas - github:/MGokcayK
*
*	Main purpose of the project is understanding sort algorithms.
*/

#include<iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

/**
* swapG is a function that swap two different parameters by its pointers.
* params should be references of parameters.
*
* @param p1 pointer of first parameter.
* @param p2 pointer of second parameters.
*/
template <typename T>
void swapG(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/**
 * Print elemets in a vector.
 *
 * @param vector vector of data.
 */
template <typename T>
void printVector(vector<T>& vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

/**
* Buble sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default is ascending.
* If it is `false`, it will be descending.
*/
template <typename T>
void bubleSort(vector<T>& vector, bool asc = true)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        for (size_t j = 0; j < vector.size() - 1 - i; j++)
        {
            if (asc == true)
            {
                if (vector[j] > vector[j + 1])
                    swapG(&vector[j], &vector[j + 1]);
            }
            else
            {
                if (vector[j] < vector[j + 1])
                    swapG(&vector[j], &vector[j + 1]);
            }
        }
    }
}


/**
* Insertion sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default is ascending.
* If it is `false`, it will be descending.
*/
template <typename T>
void insetionSort(vector<T>& vector, bool asc = true)
{
    for (size_t i = 1; i < vector.size(); i++)
    {
        T temp = vector[i];
        size_t pos = i;

        if (asc == true)
        {
            while (pos > 0 && vector[pos - 1] > temp)
            {
                vector[pos] = vector[pos - 1];
                pos--;
            }
        }
        else
        {
            while (pos > 0 && vector[pos - 1] < temp)
            {
                vector[pos] = vector[pos - 1];
                pos--;
            }
        }
        if (pos != i)
            vector[pos] = temp;
    }
}

/**
* Selection sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default is ascending.
* If it is `false`, it will be descending.
*/
template <typename T>
void selectionSort(vector<T>& vector, bool asc = true)
{
    size_t ind;
    for (size_t i = 0; i < vector.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vector.size(); j++)
        {
            ind = i;
            if (asc == true)
            {
                if (vector[j] < vector[ind])
                    ind = j;
            }
            else
            {
                if (vector[j] > vector[ind])
                    ind = j;
            }
            if (ind != i)
                swapG(&vector[i], &vector[ind]);
        }
    }
}

