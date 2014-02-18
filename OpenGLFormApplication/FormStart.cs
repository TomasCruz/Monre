using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;

using WrappedNativeApp;
using ApplicationDll;
using ThreadManager;

namespace OpenGLFormApplication
{
    public partial class FormStart : Form
    {
        private System.Windows.Forms.Label labelVerticalOffset;
        private System.Windows.Forms.Label labelRotationSpeed;
        private System.Windows.Forms.TextBox textBoxVerticalOffset;
        private System.Windows.Forms.TextBox textBoxRotationSpeed;
        private System.Windows.Forms.Button buttonRunNativeApp;

        public FormStart()
        {
            InitializeComponent();

            this.labelVerticalOffset = new System.Windows.Forms.Label();
            this.labelRotationSpeed = new System.Windows.Forms.Label();
            this.textBoxVerticalOffset = new System.Windows.Forms.TextBox();
            this.textBoxRotationSpeed = new System.Windows.Forms.TextBox();
            this.buttonRunNativeApp = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelVerticalOffset
            // 
            this.labelVerticalOffset.AutoSize = true;
            this.labelVerticalOffset.Location = new System.Drawing.Point(12, 21);
            this.labelVerticalOffset.Name = "labelVerticalOffset";
            this.labelVerticalOffset.Size = new System.Drawing.Size(73, 13);
            this.labelVerticalOffset.TabIndex = 0;
            this.labelVerticalOffset.Text = "Vertical Offset";
            // 
            // labelRotationSpeed
            // 
            this.labelRotationSpeed.AutoSize = true;
            this.labelRotationSpeed.Location = new System.Drawing.Point(12, 58);
            this.labelRotationSpeed.Name = "labelRotationSpeed";
            this.labelRotationSpeed.Size = new System.Drawing.Size(81, 13);
            this.labelRotationSpeed.TabIndex = 1;
            this.labelRotationSpeed.Text = "Rotation Speed";
            // 
            // textBoxVerticalOffset
            // 
            this.textBoxVerticalOffset.Location = new System.Drawing.Point(120, 18);
            this.textBoxVerticalOffset.Name = "textBoxVerticalOffset";
            this.textBoxVerticalOffset.Size = new System.Drawing.Size(100, 20);
            this.textBoxVerticalOffset.TabIndex = 2;
            // 
            // textBoxRotationSpeed
            // 
            this.textBoxRotationSpeed.Location = new System.Drawing.Point(120, 55);
            this.textBoxRotationSpeed.Name = "textBoxRotationSpeed";
            this.textBoxRotationSpeed.Size = new System.Drawing.Size(100, 20);
            this.textBoxRotationSpeed.TabIndex = 3;
            // 
            // buttonRunNativeApp
            // 
            this.buttonRunNativeApp.Location = new System.Drawing.Point(15, 97);
            this.buttonRunNativeApp.Name = "buttonRunNativeApp";
            this.buttonRunNativeApp.Size = new System.Drawing.Size(205, 23);
            this.buttonRunNativeApp.TabIndex = 4;
            this.buttonRunNativeApp.Text = "Run Native Application";
            this.buttonRunNativeApp.UseVisualStyleBackColor = true;
            this.buttonRunNativeApp.Click += new System.EventHandler(this.buttonRunNativeApp_Click);
            // 
            // FormStart
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(239, 137);
            this.Controls.Add(this.buttonRunNativeApp);
            this.Controls.Add(this.textBoxRotationSpeed);
            this.Controls.Add(this.textBoxVerticalOffset);
            this.Controls.Add(this.labelRotationSpeed);
            this.Controls.Add(this.labelVerticalOffset);
            this.Name = "FormStart";
            this.Text = "FormStart";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private void buttonRunNativeApp_Click(object sender, EventArgs e)
        {
            // native app
            WrappedNativeApplication app = new WrappedNativeApplication();

            // threads
            NativeAppThreadWrapper appThreadWrapper = new NativeAppThreadWrapper(textBoxVerticalOffset.Text, textBoxRotationSpeed.Text);
            GLThreadWrapper glThreadWrapper = new GLThreadWrapper(appThreadWrapper);
            NativeCallbackThreadWrapper callbackThreadWrapper = new NativeCallbackThreadWrapper();

            // thread manager
            ThreadManager.ThreadManager threadManager = new ThreadManager.ThreadManager(glThreadWrapper, appThreadWrapper, callbackThreadWrapper);
            // set ThreadManager and start application thread
            app.SetThreadManager(threadManager);

            // create and set form
            ApplicationForm appForm = new ApplicationForm();
            appForm.SetThreadManager(threadManager);

            // wrapped up and good to go
            appForm.Show();
        }
    }
}
