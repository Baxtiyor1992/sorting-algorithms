#include <iostream>
#include "ArrayPresenter.h"
#include "InsertionSort.h"

int compare(const int & first, const int & second) {
	if (first > second) {
		return 1;
	} else if (first < second) {
		return -1;
	}
	return 0;
}

int main() {
	int array[] = { 1, 3, 9, 6, 7, 8, 2, 4, 5 };
	int size = sizeof(array) / sizeof(int);

	ArrayPresenter presenter(std::cout);
	presenter.printArray(array, size);

	InsertionSort<int>* sortAlgo = new InsertionSort<int>(compare);
	sortAlgo->sort(array, size);

	presenter.printArray(array, size);	

	delete sortAlgo;

	return 0;
}
