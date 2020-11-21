#include "sorting.h"

template <typename T>
void swapG(T* p1, T* p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
// function speacialization to specify of accepted types
template void swapG(int*, int*);
template void swapG(float*, float*);
template void swapG(double*, double*);
template void swapG(std::string*, std::string*);

template <typename T>
void printVector(std::vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
// function speacialization to specify of accepted types
template void printVector(std::vector<int>&);
template void printVector(std::vector<double>&);
template void printVector(std::vector<float>&);
template void printVector(std::vector<std::string>&);

template <typename T>
void bubbleSort(std::vector<T>& vector, bool asc)
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
// function speacialization to specify of accepted typestemplate void bubbleSort(std::vector<int>& vector, bool asc);
template void bubbleSort(std::vector<double>& vector, bool asc);
template void bubbleSort(std::vector<float>& vector, bool asc);
template void bubbleSort(std::vector<std::string>& vector, bool asc);


template <typename T>
void insertionSort(std::vector<T>& vector, bool asc)
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
// function speacialization to specify of accepted types
template void insertionSort(std::vector<int>& vector, bool asc);
template void insertionSort(std::vector<double>& vector, bool asc);
template void insertionSort(std::vector<float>& vector, bool asc);
template void insertionSort(std::vector<std::string>& vector, bool asc);

template <typename T>
void selectionSort(std::vector<T>& vector, bool asc)
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
// function speacialization to specify of accepted types
template void selectionSort(std::vector<int>& vector, bool asc);
template void selectionSort(std::vector<double>& vector, bool asc);
template void selectionSort(std::vector<float>& vector, bool asc);
template void selectionSort(std::vector<std::string>& vector, bool asc);
