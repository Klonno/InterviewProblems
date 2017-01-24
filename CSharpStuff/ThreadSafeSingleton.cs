using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    class ThreadSafeSingleton
    {
        public string Str = string.Empty;

        static public ThreadSafeSingleton Singleton { get; private set; }
        static ThreadSafeSingleton()
        {
            ThreadSafeSingleton.Singleton = new ThreadSafeSingleton();
            ThreadSafeSingleton.Singleton.Str = "foo";
        }
    }
}
