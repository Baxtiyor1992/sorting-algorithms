#ifndef __EXCEPTIONS_CPP__
#define __EXCEPTIONS_CPP__

#include <string>

class Exception {
private:
	const std::string message;
public:
	Exception(std::string message) : message(message) {}

	virtual const std::string getMessage() const throw() {
		return message;
	}
};

class IllegalArgumentException : public Exception {
public:
	IllegalArgumentException(std::string message = "Invalid argument value") 
		: Exception(message) {}
};

class IndexOutOfRangeException : public IllegalArgumentException {
public:
	IndexOutOfRangeException(int index) 
		: IllegalArgumentException("Index " + std::to_string(index) + " is out of range") {}
};

#endif