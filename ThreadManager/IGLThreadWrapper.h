#ifndef _IGLThreadWrapper_h_
#define _IGLThreadWrapper_h_

#include "IThreadWrapper.h"

namespace ThreadManager
{
	public interface class IGLThreadWrapper : public IThreadWrapper
	{
		void EnqueueOpenGLInit(IntPtr windowHandle, IntPtr deviceContext, IntPtr renderingContext);
		void EnqueueOpenGLResize(int width, int height);
		void EnqueueOpenGLRender();
		void SwapOpenGLBuffers();
	};
}
#endif
