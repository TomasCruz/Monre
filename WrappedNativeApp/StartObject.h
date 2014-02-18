#ifndef _StartObject_h_
#define _StartObject_h_

namespace WrappedNativeApp
{
	public ref class StartObject
	{
	public:
		StartObject(float vertOffset, float rotSpeed);
		~StartObject();

		float verticalOffset;
		float rotationSpeed;
	};
}
#endif
