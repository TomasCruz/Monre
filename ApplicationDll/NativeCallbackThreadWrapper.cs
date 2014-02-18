using System;
using System.Threading;
using System.Collections.Generic;
using ThreadManager;

namespace ApplicationDll
{
    public class NativeCallbackThreadWrapper : CallbackThreadWrapper
    {
        public NativeCallbackThreadWrapper() : base()
        {
        }

	    public override void CreateThread()
        {
		    thread = new Thread(new ParameterizedThreadStart(this.ExecuteThread));
		    thread.Name = "callbackThread";
        }

        protected override void InitThread()
        {
        }

        protected override void DeinitThread()
        {
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
            }
            base.Dispose(disposing);
        }
    }
}
