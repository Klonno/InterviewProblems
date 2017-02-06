using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    class BSTNode
    {
        public BSTNode _left = null;
        public BSTNode _right = null;

        public int _value = 0;

        public BSTNode(int value)
        {
            _value = value;
        }
    }
    public class BST
    {
        
        /// <summary>
        /// Amazon, find the distance between two nodes in a BST.
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="value1"></param>
        /// <param name="value2"></param>
        /// <returns>retunrs the distance in nodes between the two values. Return -1 if 0 length arr, or values not found
        /// Return 0 if the values are the same (they would be in the same node)</returns>
        static public int FindEdges(int[] arr, int value1, int value2)
        {
            int distance = -1;
            int value1Distance = -1;
            int value2Distance = -1;
            int addedDistance = 0;      // How far is the added node from the head

            // No need to continue if array is empty
            if (arr.Length != 0)
            {

                // Build BST
                // Add head
                int mid = arr.Length / 2;
                BSTNode head = new BSTNode(arr[mid]);
                if (arr[mid] == value1)
                {
                    value1Distance = addedDistance;
                }
                if (arr[mid] == value2)
                {
                    value2Distance = addedDistance;
                }

                int i, j;
                for (i = mid - 1, j = mid + 1; (i >= 0 || j < arr.Length); --i, ++j)
                {
                    if (i >= 0)
                    {
                        addedDistance = AddNode(head, arr[i], 1);
                        if (arr[i] == value1)
                        {
                            value1Distance = addedDistance;
                        }
                        if (arr[i] == value2)
                        {
                            value2Distance = addedDistance;
                        }
                    }
                    if (j < arr.Length)
                    {
                        addedDistance = AddNode(head, arr[j], 1);
                        if (arr[j] == value1)
                        {
                            value1Distance = addedDistance;
                        }
                        if (arr[j] == value2)
                        {
                            value2Distance = addedDistance;
                        }
                    }
                }
            }
            if (value1Distance != -1 && value2Distance != -1)
            {
                distance = value1Distance + value2Distance;
            }
            return distance;
        }


        static private int AddNode2(BSTNode head, int value, int distance)
        {
            if (head is BSTNode)
            {
                if (head._value < value)    // Greater than, go right
                {
                    if (head._right is BSTNode)
                    {
                        distance = AddNode(head._right, value, ++distance);
                    }
                    else
                    {
                        head._right = new BSTNode(value);
                    }
                }
                else if (head._value > value) // Less than, go left
                {
                    if (head._left is BSTNode)
                    {
                        distance = AddNode(head._left, value, ++distance);
                    }
                    else
                    {
                        head._left = new BSTNode(value);
                    }
                }
            }
            return distance;
        }

        static private int AddNode(BSTNode head, int value, int distance)
        {
            if (head is BSTNode)
            {
                if (head._value < value)    // Greater than, go right
                {
                    if (head._right is BSTNode)
                    {
                        distance = AddNode(head._right, value, ++distance);
                    }
                    else
                    {
                        head._right = new BSTNode(value);
                    }
                }
                else if (head._value > value) // Less than, go left
                {
                    if (head._left is BSTNode)
                    {
                        distance = AddNode(head._left, value, ++distance);
                    }
                    else
                    {
                        head._left = new BSTNode(value);
                    }
                }
            }
            return distance;
        }
    }
}
