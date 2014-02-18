#include "NativeException.h"

NativeException::NativeException(char* paramMessage)
{
	message = std::string(paramMessage);
}

NativeException::NativeException(const NativeException& rhs)
{
	message = rhs.message;
}

NativeException::~NativeException()
{
}

const std::string& NativeException::GetInfo() const
{
	return message;
}
