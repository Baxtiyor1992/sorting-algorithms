#ifndef __ARRAY_PRESENTER_CPP__
#define __ARRAY_PRESENTER_CPP__

#include "ArrayPresenter.h"

ArrayPresenter::ArrayPresenter(std::ostream & outputStream) : AbstractPresenter(outputStream) {}

void ArrayPresenter::printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		getOutputStream() << array[i] << ' ';
	}
	getOutputStream() << '\n';
}

#endif