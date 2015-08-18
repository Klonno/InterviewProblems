using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace CountLinesInterviewQuestion
{
    // Do not count whitespaces or comment lines
    public class LineCounter : ILineCounter
    {
        ///
        /// <returns>-1 if error</returns>
        ///
        public int CountLines(string filePath)
        {
            int numLines = 0;
            bool inCommentBlock = false;
        
            try
            {
                using(TextReader tr = File.OpenText(filePath))
                {
                    string line = string.Empty;

                    // assuming ReadLine bumps file position
                    while((line = tr.ReadLine()) != null)
                    {
                        // What if "/*" or "//" is in a string?
                        // Need to solve lines that contain valid code AND comments
                        // Problem : /* foo */ int x;
                        line = line.Trim();
                        
                        if (inCommentBlock == false)
                        {
                            inCommentBlock = line.Contains("/*");
                        }
                        if (!string.IsNullOrWhiteSpace(line) && inCommentBlock == false && line.StartsWith("//")  == false)
                        {
                            ++numLines;
                        }
                        if (inCommentBlock == true)
                        {
                            if (line.Contains("*/"))
                            {
                                inCommentBlock = false;
                            }
                        }

                    }
                }
            }
            catch (Exception e)
            {
                numLines = -1;
                System.Diagnostics.Debug.WriteLine(e.Message);
            }
            return numLines;            
        }
    }   


    class Program
    {
        static void Main(string[] args)
        {
            LineCounter counter = new LineCounter();

            int count = counter.CountLines(@"C:\Users\scott\Documents\Visual Studio 2013\Projects\CountLinesInterviewQuestion\CountLinesInterviewQuestion\InterfaceFile.cs");
        }
    }
}
