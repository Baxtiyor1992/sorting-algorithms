#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#include "AbstractSortAlgorithm.h"

template <typename T>
class InsertionSort : public AbstractSortAlgorithm<T> {

public:
	InsertionSort(int (*compare_function)(const T & first, const T & second));

	virtual void sort(T array[], int size);
};

#include "InsertionSort.cpp"

#endif
