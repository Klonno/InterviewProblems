using Microsoft.VisualStudio.TestTools.UnitTesting;
using CSharpStuff;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff.Tests
{
    [TestClass()]
    public class BSTTests
    {
        [TestMethod()]
        public void FindEdgesTest()
        {
            int[] arr = new int[] { 2 };
            int distance = BST.FindEdges(arr, 2, 2);
            if (distance != 0) {
                Assert.Fail();
            }

            arr = new int[] { };
            distance = BST.FindEdges(arr, 2, 2);
            if (distance != -1)
            {
                Assert.Fail("distance should = -1");
            }

            arr = new int[] { 2, 5, 1, 6 };
            distance = BST.FindEdges(arr, 2, 7);
            if (distance != -1)
            {
                Assert.Fail("distance should = -1");
            }
        }
    }
}