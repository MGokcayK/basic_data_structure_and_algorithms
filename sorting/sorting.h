/*
*	@Author : Mehmet Gokcay Kabatas - github:/MGokcayK
*
*	Main purpose of the project is understanding sort algorithms.
*/
#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

/**
* swapG is a function that swap two different parameters by its pointers.
* params should be references of parameters.
*
* @param p1 pointer of first parameter.
* @param p2 pointer of second parameters.
*/
template <typename T>
void swapG(T *p1, T *p2);

/**
 * Print elemets in a vector.
 *
 * @param vector vector of data.
 */
template <typename T>
void printVector(std::vector<T>& vector);

/**
* Bubble sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default asc is `true`.
* If it is `false`, it will be descending.
*/
template <typename T>
void bubbleSort(std::vector<T> &vector, bool asc=true);

/**
* Insertion sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default asc is `true`.
* If it is `false`, it will be descending.
*/
template <typename T>
void insertionSort(std::vector<T> &vector, bool asc=true);

/**
* Selection sorting of vector.
*
* @param vector vector of data.
* @param asc sorting order. Default asc is `true`.
* If it is `false`, it will be descending.
*/
template <typename T>
void selectionSort(std::vector<T> &vector, bool asc=true);