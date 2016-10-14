using System;
using System.Collections.Generic;
using System.Text;

namespace TwoSum
{

    public class Solution
    {
        // 下面的代码排名只击败了36.24%的人员。算法复杂度是O(n^2)
        public int[] TwoSum(int[] nums, int target)
        {
            int[] ret = new int[2];

            int firstLoopCount = nums.Length - 1;
            int secondLoopCount = nums.Length;

            for (int i = 0; i < firstLoopCount; ++i)
            {
                for (int j = i + 1; j < secondLoopCount; ++j)
                {
                    if (target == (nums[i] + nums[j]))
                    {
                        ret[0] = i;
                        ret[1] = j;
                        return ret;
                    }
                }
            }

            return ret;
        }

        // 构建一个hash表，然后直接看第二个数字是否存在.下面的答案位于98.69%的位置。
        // 这其实挺无聊的吧。纯粹的空间换时间。
        public int[] TwoSum2(int[] nums, int target)
        {
            int[] ret = new int[2];
            Dictionary<int, int> valueToIndex = new Dictionary<int, int>(nums.Length);
            for (int i = 0; i < nums.Length; ++i)
            {
                valueToIndex[nums[i]] = i;
            }

            for (int i = 0; i < nums.Length; ++i)
            {
                int diff = target - nums[i];
                int secondIndex;        
                if (valueToIndex.TryGetValue(diff,out secondIndex))
                {
                    if (i != secondIndex)
                    {
                        ret[0] = i;
                        ret[1] = secondIndex;
                        return ret;
                    }

                }
            }

            return ret;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = { 2, 7, 11, 15 };
            Solution solution = new Solution();
            int[] ret = solution.TwoSum2(nums, 9);

            System.Console.WriteLine(string.Format("{0} {1}", ret[0], ret[1]));
            System.Console.ReadLine();
        }
    }
}
