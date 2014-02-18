#ifndef _NativeException_h_
#define _NativeException_h_

#include <string>

class NativeException
{
private:
	std::string message;

public:
	NativeException(char* paramMessage);
	NativeException(const NativeException& rhs);
	~NativeException();
	const std::string& GetInfo() const;
};
#endif
