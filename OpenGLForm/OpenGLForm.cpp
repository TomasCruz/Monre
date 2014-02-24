#include <windows.h>
#include "OpenGLForm.h"

namespace OpenGLForm
{
	OpenGLForm::OpenGLForm()
	{
		InitializeComponent();

		threadManager = nullptr;
		isFullScreen = false;
	}

	OpenGLForm::~OpenGLForm()
	{
		if (components)
			delete components;

		threadManager->TerminateThreads();
	}

	void OpenGLForm::OpenGLForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		threadManager->EnqueueStartGLThread(Handle, this->ClientRectangle.Width, this->ClientRectangle.Height);
	}

	void OpenGLForm::Refresh()
	{
		threadManager->EnqueueOpenGLRender();
	}

	void OpenGLForm::OnPaint(PaintEventArgs^ e)
	{
		threadManager->EnqueueOpenGLRender();
	}

	void OpenGLForm::OnResize(EventArgs^ e)
	{
		if (threadManager)
			threadManager->EnqueueOpenGLResize(this->ClientRectangle.Width, this->ClientRectangle.Height);
	}

	void OpenGLForm::OnPaintBackground(PaintEventArgs^ e)
	{
	}

	CreateParams^ OpenGLForm::CreateParams::get()
	{
		 System::Windows::Forms::CreateParams^ cp = __super::CreateParams;

		// Set the position on the form
		cp->X = 0;
		cp->Y = 0;
		cp->Width = this->ClientRectangle.Width;
		cp->Height = this->ClientRectangle.Height;

		// Create so that the form's window is OpenGL compliant (no clipping)
		int style = (isFullScreen) ? WS_OVERLAPPED : WS_OVERLAPPEDWINDOW;
		cp->Style = style | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		
		return cp;
	}

	void OpenGLForm::SetThreadManager(IThreadManager^ paramThreadManager)
	{
		threadManager = paramThreadManager;
	}

	// custom callback actions exist, but are empty by default
	void OpenGLForm::ExecuteCustomAction1(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction2(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction3(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction4(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction5(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction6(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction7(Object^ arg) {}
	void OpenGLForm::ExecuteCustomAction8(Object^ arg) {}

	void OpenGLForm::ToggleFullScreen()
	{
		if (InvokeRequired)
		{
			VoidVoidDelegate^ fullScreenDelegate = gcnew VoidVoidDelegate(this, &OpenGLForm::ToggleFullScreen);
			Invoke(fullScreenDelegate);
			return;
		}

		isFullScreen = !isFullScreen;

		if (isFullScreen)
		{
			windowWidth = this->ClientRectangle.Width;
			windowHeight = this->ClientRectangle.Height;
			bounds = this->Bounds;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			int xSize = GetSystemMetrics(SM_CXSCREEN), ySize = GetSystemMetrics(SM_CYSCREEN);
			::SetWindowPos((HWND)this->Handle.ToPointer(), HWND_TOP, 0, 0, xSize, ySize, SWP_SHOWWINDOW);
			threadManager->EnqueueOpenGLResize(xSize, ySize);
		}
		else
		{
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
			this->Bounds = bounds;
			threadManager->EnqueueOpenGLResize(windowWidth, windowHeight);
		}
	}
}
