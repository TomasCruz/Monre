using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Forms;

namespace OpenGLFormApplication
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [MTAThread]
        static void Main()
        {
            Thread.CurrentThread.Name = "uiThread";
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormStart());
        }
    }
}
