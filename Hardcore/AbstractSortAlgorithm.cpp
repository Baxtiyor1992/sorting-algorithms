#ifndef __ABSTRACT_SORT_ALGORITHM_CPP__
#define __ABSTRACT_SORT_ALGORITHM_CPP__

#include "AbstractSortAlgorithm.h"

template <typename T>
AbstractSortAlgorithm<T>::AbstractSortAlgorithm(int (*compare_function)(const T & first, const T & second)) {
	this->compare_function = compare_function;
	resetCounters();
}

template <typename T>
int AbstractSortAlgorithm<T>::compare(const T & first, const T & second) {
	this->comparationsCount++;

	return this->compare_function(first, second);
}

template <typename T>
void AbstractSortAlgorithm<T>::resetCounters() {
	this->comparationsCount = 0;
	this->swapsCount = 0;
}

#endif