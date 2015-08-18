using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel.DataAnnotations;

namespace CSharpStuff
{            
    delegate int LambdaDelegate (int x);

    class Program
    {
        //
        // Data Annotations allow you to apply attributes to the class or members that
        // specify validation rules, specify how the data is displayed, and set relationships
        // between classes. The System.ComponentModel.DataAnnotations namespace contains the
        // classes that are used as data attributes. By applying these attributes on the data 
        // class or member, you centralize the data definition and do not have to re-apply 
        // the same rules in multiple places.
        // The data annotation attributes fall into three categories: validation attributes, display attributes, and data modeling attributes. This topic describes these attributes and provides examples.
        //
        [Display(Name = "Product Number")]
        [Range(0, 5000)]
        public int ProductID { get; set; }

        [Display(Name = "Name")]
        [Required]
        public string ProductName { get; set; }

        [Display(Name = "Price")]
        [DataType(DataType.Currency)]
        public double ListPrice { get; set; }

        [Display(Name = "Available")]
        public bool InStock { get; set; }
        
        static void Main(string[] args)
        {
      
            // Error	2	'CSharpStuff.TestClass' does not contain a constructor that takes 0 arguments	C:\Users\scott\Documents\Visual Studio 2013\Projects\InterviewProblems\CSharpStuff\Program.cs	12	35	CSharpStuff
            // when overiding the default ctor a default ctor IS NOT created.
            // TestClass testClass = new TestClass();
            TestClass testClass = new TestClass(1);

            RefClass refClass = new RefClass();
            RefClass test;
            string foo = "bar";
            List<string> strings =  new List<string> () {"x","y"};

            // var what is a var? 
            // Beginning in Visual C# 3.0, variables that are declared at method scope can have an implicit type var. 
            // An implicitly typed local variable is strongly typed just as if you had declared the type yourself,
            // but the compiler determines the type.
            //
            var result = from str in strings
                         select str; 

            var result1 = from str1 in strings
                     where str1 == "x"
                     select str1;

            // A lambda expression is an anonymous function that you can use to create 
            // delegates or expression tree types. By using lambda expressions, you can 
            // write local functions that can be passed as arguments or returned as
            // the value of function calls. Lambda expressions are particularly helpful for 
            // writing LINQ query expressions.
            LambdaDelegate myDelegate = x => x * x; 
            int j = myDelegate(5); //j = 25

            // Lambdas operators are used in method-based LINQ queries as arguments to standard 
            // query operator methods such as Where.
            var result2 = strings.Where(str2 => str2 == "y");

            char [] ch = foo.ToCharArray();
            ch[0] = 'a';
            foo = new string(ch);

            test = refClass; // Test is now a reference to the reference type RefClass refClass;

            //
            // All reference values were changed in ChangeRefType
            //
            testClass.ChangeRefType(refClass);
            
            //
            // string is a reference type, but does not behave like a reference type!
            // The string paramater is not changed!
            //
            testClass.ChangeRefType(foo);

            //
            // This will change the string!
            //
            testClass.ChangeRefType(ref foo);

            //
            // Will throw exception System.OverflowException if the sum of a+b
            // exceeds Maximum integer value = 2147483647
            //
            int a = 100, b = 200;
            int c;

            try
            {
                c = checked(a + b);
            }
            catch (System.OverflowException e)
            {
                Console.WriteLine(e.Message);
            }

        }

    }
}
