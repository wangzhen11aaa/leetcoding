/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.12%)
 * Likes:    1498
 * Dislikes: 197
 * Total Accepted:    445.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0]>=target?0:1;
        return bs(nums, 0, n-1, target);
    }
    int bs(vector<int> &nums, int s, int e, int target){
        if(s>=e){
            if(nums[s] >= target) return s;
            else return s+1;
        }
        int m = (s + e) / 2;
        if (target == nums[m])
            return m;
        else if (nums[m] > target)
            return bs(nums, s, m - 1, target);
        else
            return bs(nums, m + 1, e, target);
    }
};

