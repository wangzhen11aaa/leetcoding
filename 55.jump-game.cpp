/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (32.52%)
 * Likes:    2444
 * Dislikes: 232
 * Total Accepted:    311.5K
 * Total Submissions: 954K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
// At position p, we choose the maximum result from current view, if we can get to the end,
// then the algorithm ends.
// Ex: [2,3,1,1,4] from position 0, we can get 3 or 1, and 1+3 > 2+1, so we choose 3.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) return true;
        for(int i = 0; i < length; ){
            int v = nums[i];
            if(v == 0) return false;
            {
                int n_i = 0;
                int max_jump = 0;
                for(auto j = 1; j <= v && i+j < length; j++){
                    int n_j = nums[i+j];
                    if(n_j+j+i >= length -1) return true;
                    else{
                        if (max_jump < n_j+i+j)
                        { 
                                max_jump = n_j + i + j;
                                n_i = i+j;
                        }
                    }
                    
                }
                i = n_i;
            }
        }
        return true;
    }
};
// @lc code=end

