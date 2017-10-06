#ifndef __ARRAY_PRESENTER_H__
#define __ARRAY_PRESENTER_H__

#include <ostream>
#include "AbstractPresenter.h"

class ArrayPresenter : public AbstractPresenter {

public:
	ArrayPresenter(std::ostream & outputStream);

	void printArray(int array[], int size);
};

#endif