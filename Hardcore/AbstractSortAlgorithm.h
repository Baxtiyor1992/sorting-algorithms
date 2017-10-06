#ifndef __ABSTRACT_SORT_ALGORITHM_H__
#define __ABSTRACT_SORT_ALGORITHM_H__

template <typename T>
class AbstractSortAlgorithm {

private:
	int (*compare_function)(const T & first, const T & second);
	int comparationsCount;
	int swapsCount;

protected:
	int compare(const T & first, const T & second);

public:
	AbstractSortAlgorithm(int (*compare_function)(const T & first, const T & second));

	void resetCounters();

	virtual void sort(T array[], int size) = 0;
};

#include "AbstractSortAlgorithm.cpp"

#endif