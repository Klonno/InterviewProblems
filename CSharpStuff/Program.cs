using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics;

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
        [Range(0, 5000, ErrorMessage = "Value out of range")]
        static public int ProductID { get; set; }

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

            // DataAnnotation
            ProductID = 5001;

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

            ThreadSafeSingleton singleton = ThreadSafeSingleton.Singleton;
            ThreadSafeSingleton singleton2 = ThreadSafeSingleton.Singleton;

            Reverser reverser = new Reverser();

            int reversedInt = reverser.Reverse(321);
            string reversedString = reverser.Reverse("foobars");


            // lLass is a reference object, equal operator sets a REFERENCE to the object.
            // STruct is a value object, equal operator creates a new shallow copy.
            ChessBoard chessBoard = new ChessBoard();
            chessBoard.PlayerName = "Bill";
            // chessboard1 is now a reference to chessboard.
            ChessBoard chessBoard1 = chessBoard;
            // both chessboard and chessboard1 have the name "Jo" now.
            chessBoard1.PlayerName = "Jo";
            TestStruct testA = new TestStruct();
            testA.Name = "foo";
            TestStruct testB;
            // TestB is a shallow copy of TestA
            testB = testA;
            // TestB has the name "bar", TestB still has the name "foo".
            testB.Name = "bar";

            int[] arr = new int[] { 2 };
            int distance = BST.FindEdges(arr, 2, 2);
            //Debug.Assert(distance == 0, "distance should = 0");

            //arr = new int [] { };
            //distance = BST.FindEdges(arr, 2, 2);
            //Debug.Assert(distance == -1, "distance should = -1");

            //arr = new int[] { 2, 5, 1, 6 };
            //distance = BST.FindEdges(arr, 2, 7);
            //Debug.Assert(distance == -1, "distance should = -1");

            //arr = new int[] { 2, 5, 1, 6 };
            //distance = BST.FindEdges(arr, 1, 6);
            //Debug.Assert(distance == 2, "distance should = 2");

            arr = new int[] {7, 2, 5, 1, 6 };
            distance = BST.FindEdges(arr, 1, 6);
            //      Debug.Assert(distance == 2, "distance should = 2");

            // Expected output  "eth quick nworb..."
            string reverseEveryOther = "The quick brown fox jumped over the lazy dog";
            string everyOtherReversed = reverser.ReverseEveryOtherWord(reverseEveryOther);
            Console.WriteLine(everyOtherReversed);

        }

    }
}
