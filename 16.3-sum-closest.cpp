/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    1284
 * Dislikes: 92
 * Total Accepted:    374.9K
 * Total Submissions: 819.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int optimized_delta = numeric_limits<int>::max();
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while (l < r){
                int delta = (nums[i] + nums[l] + nums[r]) - target;
                if (delta == 0) return target;
                // If delta is less than 0, means that we shoud move right l to be closer to target.
                if(delta < 0){
                    l++;
                    if(abs(delta) < abs(optimized_delta)){
                        optimized_delta = delta;
                    }
                }
                else{
                    r--;
                    if(abs(delta) < abs(optimized_delta)){
                        optimized_delta = delta;
                    }
                }
            }
        }
        return optimized_delta + target;
    }
};

