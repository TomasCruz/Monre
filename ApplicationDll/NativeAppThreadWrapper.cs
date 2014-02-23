using System;
using System.Threading;
using System.Reflection;
using System.Collections.Generic;
using ThreadManager;

namespace ApplicationDll
{
    public class NativeAppThreadWrapper : AppThreadWrapper
    {
        private float verticalOffset;
        private float rotationSpeed;
        private WrappedNativeApp.StartObject startObject;

        public NativeAppThreadWrapper(string verticalOffsetString, string rotationSpeedString)
            : base()
        {
            startObject = null;

            if (verticalOffsetString == null || verticalOffsetString == "")
                verticalOffset = 0.2f; // default
            else
            {
                try { verticalOffset = float.Parse(verticalOffsetString); }
                catch (Exception e) { System.Windows.Forms.MessageBox.Show("Normal float only please\n\n" + e.ToString()); throw e; }
            }

            if (rotationSpeedString == null || rotationSpeedString == "")
                rotationSpeed = 0.5f; // default
            else
            {
                try { rotationSpeed = float.Parse(rotationSpeedString); }
                catch (Exception e) { System.Windows.Forms.MessageBox.Show("Normal float only please\n\n" + e.ToString()); throw e; }
            }

            startObject = new WrappedNativeApp.StartObject(verticalOffset, rotationSpeed);
        }

	    public override void CreateThread()
        {
		    thread = new Thread(new ParameterizedThreadStart(this.ExecuteThread));
		    thread.Name = "appThread";
        }

		protected override void InitThread()
        {
			String keyString = AppThreadActionStrings.nativeApplicationStartString;
			if (!delegateDictionary.ContainsKey(keyString))
				return;

            Delegate nativeApplicationStartDelegate = delegateDictionary[keyString];
            try { nativeApplicationStartDelegate.DynamicInvoke(startObject); }
            catch (TargetInvocationException tie)
            {
                NativeExceptionBase inner = (NativeExceptionBase)tie.InnerException;
                System.Windows.Forms.MessageBox.Show(inner.ToString());
                Environment.Exit(1);
            }
    		catch(System.Reflection.TargetParameterCountException tpce) { System.Windows.Forms.MessageBox.Show(tpce.ToString()); }
        }

		protected override void DeinitThread()
        {
		    String keyString = AppThreadActionStrings.nativeApplicationDestroyString;
		    if (!delegateDictionary.ContainsKey(keyString))
			    return;

		    Delegate nativeApplicationDestroyDelegate = delegateDictionary[keyString];
		    try { nativeApplicationDestroyDelegate.DynamicInvoke(null); }
            catch (TargetInvocationException tie)
            {
                NativeExceptionBase inner = (NativeExceptionBase)tie.InnerException;
                System.Windows.Forms.MessageBox.Show(inner.ToString());
                Environment.Exit(1);
            }
            catch (System.Reflection.TargetParameterCountException tpce) { System.Windows.Forms.MessageBox.Show(tpce.ToString()); }
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
