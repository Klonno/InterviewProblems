using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    class Reverser
    {
        public string Reverse(string str)
        {
            int lastIndex;
            char temp;

            // If the input string is Empty or Whitespaces then
            // it cannot be reversed.
            if (string.IsNullOrWhiteSpace(str))
            {
                return str;
            }

            // Allocate a char array since you cannot assign a string object char as an index(er). 
            char[] revArray = new char[str.Length];
            lastIndex = str.Length - 1;

            // Now reverse the string
            for (int i = 0; i <= lastIndex; ++i, --lastIndex)
            {
                temp = str[lastIndex];
                revArray[lastIndex] = str[i];
                revArray[i] = temp;
            }
            
            return new string(revArray);
        }
        public int Reverse(int x)
        {
            int rev = 0;
            try
            {
                while (x != 0)
                {
                    rev = rev * 10 + x % 10;
                    x = x / 10;
                }
            }
            catch (OverflowException oex)
            {
                System.Diagnostics.Debug.WriteLine(oex.Message);
            }
            return rev;
        }
    }
}
