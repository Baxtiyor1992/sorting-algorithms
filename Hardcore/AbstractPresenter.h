#ifndef __ABSTRACT_PRESENTER_H__
#define __ABSTRACT_PRESENTER_H__

#include <ostream>

class AbstractPresenter {

private:
	std::ostream& outputStream;

public:
	AbstractPresenter(std::ostream & outputStream);

	std::ostream & getOutputStream();
};

#endif