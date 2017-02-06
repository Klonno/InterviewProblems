using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    struct TestStruct
    {
        // protected UriIdnScope not allowed
        private int X { get; set; }

        public string Name { get; set; }
    }
}
