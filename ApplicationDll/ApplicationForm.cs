using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using OpenGLForm;
using ThreadManager;

namespace ApplicationDll
{
    public partial class ApplicationForm : OpenGLForm.OpenGLForm
    {
        public ApplicationForm() : base()
        {
            InitializeComponent();

            this.KeyDown += new KeyEventHandler(this.ApplicationForm_KeyDown);
            this.KeyUp += new KeyEventHandler(this.ApplicationForm_KeyUp);
        }

        private void ApplicationForm_KeyDown(Object sender, KeyEventArgs e)
        {
            threadManager.EnqueueKeyDown(e);
        }

        private void ApplicationForm_KeyUp(Object sender, KeyEventArgs e)
        {
            threadManager.EnqueueKeyUp(e);
        }

        public override void SetThreadManager(IThreadManager paramThreadManager)
        {
            // base.SetThreadManager first.
            base.SetThreadManager(paramThreadManager);

            // Now spin up callback thread
            List<Object> threadList = new List<Object>();
            threadList.Add(new KeyValuePair<String, Delegate>(CallbackThreadActionStrings.customAction1String, new VoidObjectDelegate(this.ExecuteCustomAction1)));
            threadList.Add(new KeyValuePair<String, Delegate>(CallbackThreadActionStrings.fullScreenString, new VoidVoidDelegate(this.ToggleFullScreen)));
            threadManager.StartCallbackThread(threadList);
        }

        public override void ExecuteCustomAction1(Object arg)
        {
            if (InvokeRequired)
            {
                Invoke(new MethodInvoker(() => { ExecuteCustomAction1(arg); }));
                return;
            }
            MessageBox.Show(arg.ToString());
        }
    }
}
