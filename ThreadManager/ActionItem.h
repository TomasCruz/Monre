#ifndef _ActionItem_h_
#define _ActionItem_h_

using namespace System;

namespace ThreadManager
{
	public ref class ActionItem
	{
	private:
		Delegate^ actionDelegate;
		array<Object^>^ arguments;

	public:
		ActionItem(Delegate^ dlgt, array<Object^>^ args);
		~ActionItem();

		property Delegate^ ActionDelegate { virtual Delegate^ get(); }
		property array<Object^>^ Arguments { virtual array<Object^>^ get(); }
	};
}
#endif
