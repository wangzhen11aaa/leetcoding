/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (28.72%)
 * Likes:    1417
 * Dislikes: 83
 * Total Accepted:    189.5K
 * Total Submissions: 659.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        int res = 1;
        if (length == 1)
            return 0;
        for (int i = 0; i < length;)
        {
            int v = nums[i];
            if (i + v >= length - 1)
                return res;

            int n_i = 0;
            int max_jump = 0;
            for (auto j = 1; j <= v && i + j < length; j++)
            {
                int n_j = nums[i + j];

                if (n_j + j + i >= length - 1)
                    return ++res;

                if (max_jump < n_j + i + j)
                {
                    max_jump = n_j + i + j;
                    n_i = i + j;
                }
            }
            res++;
            i = n_i;
        }
        return res;
    }
};
// @lc code=end

