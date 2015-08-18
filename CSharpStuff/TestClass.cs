using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    public class RefClass
    {
        public int AutoImplementedProperty {get; set;}

        public void Change(RefClass r)
        {
            r.AutoImplementedProperty = 100;
        }

        public RefClass()
        {
            this.AutoImplementedProperty = 0;
        }
    }
    class TestClass
    {
        public int X { get;private set;}

        /// <summary>
        /// When overiding the default ctor, a default ctor IS NOT created.
        /// </summary>
        /// <param name="x"></param>
        public TestClass(int x)
        {
            this.X = x;
        }

        public void ChangeRefType(ref string s)
        {
            s += " foo bar!";
        }

        public void ChangeRefType(string s)
        {
            s += " foo bar!";
        }

        public void ChangeRefType(RefClass r)
        {
            r.Change(r);
        }

        public static int operator +  (TestClass xc, TestClass yc)
        {
            int x = xc.X + yc.X;
            return x;
        }
    }
}
