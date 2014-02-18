#include "ActionItem.h"

namespace ThreadManager
{
	ActionItem::ActionItem(Delegate^ dlgt, array<Object^>^ args) : actionDelegate(dlgt), arguments(args)
	{
	}

	ActionItem::~ActionItem()
	{
	}

	Delegate^ ActionItem::ActionDelegate::get() { return actionDelegate; }
	array<Object^>^ ActionItem::Arguments::get() { return arguments; }
}
