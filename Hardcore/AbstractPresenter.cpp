#ifndef __ABSTRACT_PRESENTER_CPP__
#define __ABSTRACT_PRESENTER_CPP__

#include "AbstractPresenter.h"

AbstractPresenter::AbstractPresenter(std::ostream & outputStream) : outputStream(outputStream) {}

std::ostream & AbstractPresenter::getOutputStream() {
	return this->outputStream;
}

#endif