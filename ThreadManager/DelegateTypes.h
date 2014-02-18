#ifndef _DelegateTypes_h_
#define _DelegateTypes_h_

public delegate void VoidVoidDelegate(void);
public delegate void VoidIntPtrVoidIntIntDelegate(IntPtr, int, int);
public delegate void VoidIntIntDelegate(int, int);
public delegate void VoidObjectDelegate(Object^);
public delegate void VoidIntPtr3Delegate(IntPtr, IntPtr, IntPtr);

#endif
