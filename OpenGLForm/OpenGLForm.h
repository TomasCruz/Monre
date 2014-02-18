#ifndef _OpenGLForm_h_
#define _OpenGLForm_h_

#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#using "ThreadManager.dll"

using namespace System;
using namespace System::Windows::Forms;
using namespace ThreadManager;

namespace OpenGLForm
{
	public ref class OpenGLForm : public System::Windows::Forms::Form
	{
	public:
		OpenGLForm();
		~OpenGLForm();

		virtual void Refresh() override;
		virtual void SetThreadManager(IThreadManager^ paramThreadManager);
		virtual void ExecuteCustomAction1(Object^ arg);
		virtual void ExecuteCustomAction2(Object^ arg);
		virtual void ExecuteCustomAction3(Object^ arg);
		virtual void ExecuteCustomAction4(Object^ arg);
		virtual void ExecuteCustomAction5(Object^ arg);
		virtual void ExecuteCustomAction6(Object^ arg);
		virtual void ExecuteCustomAction7(Object^ arg);
		virtual void ExecuteCustomAction8(Object^ arg);

	protected:
		bool isFullScreen;
		int windowWidth, windowHeight;
		System::Drawing::Rectangle bounds;
		IThreadManager^ threadManager;

		virtual void OnPaint(PaintEventArgs^ e) override;
		virtual void OnPaintBackground(PaintEventArgs^ e) override;
		virtual void OnResize(EventArgs^ e) override;
		virtual void ToggleFullScreen();

		property System::Windows::Forms::CreateParams^ CreateParams
		{
			virtual System::Windows::Forms::CreateParams^ get() override;
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// OpenGLForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"OpenGLForm";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &OpenGLForm::OpenGLForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		void OpenGLForm_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
#endif
