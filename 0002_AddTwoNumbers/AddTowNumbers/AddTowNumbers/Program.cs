using System;
using System.Collections.Generic;
using System.Text;

namespace AddTowNumbers
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        // 2016-10-14 beats 90.78% of c#
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            // dump. 
            ListNode ret = new ListNode(0);
            ListNode cur = ret;

            // 是否进位的标示
            int carry = 0;
            
            while (l1 != null && l2 != null)
            {
                int sum = carry;
                sum += l1.val;
                sum += l2.val;

                cur.next = new ListNode(0);

                if (sum < 10)
                {
                    cur.next.val = sum;
                    carry = 0;
                }
                else
                {
                    cur.next.val = sum - 10;
                    carry = 1;
                }

                cur = cur.next;
                l1 = l1.next;
                l2 = l2.next;
            }

            // add l1 if l1 has number
            while (l1 != null)
            {
                int sum = carry;
                sum += l1.val;
                cur.next = new ListNode(0);

                if (sum < 10)
                {
                    cur.next.val = sum;
                    carry = 0;
                }
                else
                {
                    cur.next.val = sum - 10;
                    carry = 1;
                }

                cur = cur.next;
                l1 = l1.next;
            }

            // add l2 if l2 has number
            while (l2 != null)
            {
                int sum = carry;
                sum += l2.val;
                cur.next = new ListNode(0);

                if (sum < 10)
                {
                    cur.next.val = sum;
                    carry = 0;
                }
                else
                {
                    cur.next.val = sum - 10;
                    carry = 1;
                }

                cur = cur.next;
                l2 = l2.next;
            }

            // when first submitted , this condition did not include.to fix Bug: {5} + {5}, should get {0->1}, but only get {0}
            if (carry > 0)
            {
                cur.next = new ListNode(carry);
                cur = cur.next;
            }


            return ret.next;
        }



    }

    class Program
    {
        static ListNode ConstructList(int[] data)
        {
            System.Diagnostics.Debug.Assert(data.Length > 0);

            ListNode l = new ListNode(data[0]);
            ListNode cur = l;
            for (int i = 1; i < data.Length; ++i)
            {
                cur.next = new ListNode(data[i]);
                cur = cur.next;
            }
            return l;
        }

        static void Main(string[] args)
        {
            //  construct listnode1 
            ListNode l1 = ConstructList( new int[] {2,4,3} );

            ListNode l2 = ConstructList(new int[] { 5, 6, 4 });

            Solution solution = new Solution();
            ListNode ret = solution.AddTwoNumbers(l1, l2);

            while(ret!=null)
            {
                System.Console.Write(ret.val);
                System.Console.Write("->");
                ret = ret.next;
            }
            System.Console.Write("/n");
            System.Console.ReadLine();
            
        }
    }
}
