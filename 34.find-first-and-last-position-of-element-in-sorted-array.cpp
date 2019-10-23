/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.04%)
 * Likes:    1885
 * Dislikes: 97
 * Total Accepted:    339.4K
 * Total Submissions: 995.1K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    // [5,8,8,8,8,10] Binary search to find the first item.
    // Then Binary search find leftest and rightest.
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        if(n == 0) {res = {-1,-1};return res;}
        if(n == 1){if(nums[0]==target){res={0,0}; return res;}else{res={-1,-1};return res;}}
        else{
            int idx = binarySearch(nums, 0, n-1, target);
            if(idx == -1) res = {-1, -1};
            else{
                int leftest_idx, rightest_idx;
                leftest_idx = rightest_idx = -1;
                // Get leftest index
                if(idx == 0){
                    leftest_idx = 0;
                    while(idx < n-1){
                        if(nums[idx] == nums[idx+1]) rightest_idx = ++idx;
                        else{
                            rightest_idx = idx;
                            break;
                        }
                    }
                }
                else if(idx == n-1){
                    rightest_idx = n-1;
                    while(idx > 0){
                        if(nums[idx] == nums[idx-1]) leftest_idx = --idx;
                        else{
                            leftest_idx=idx;
                            break;
                        }
                    }
                }
                else{
                    int m_idx = idx;
                    while (m_idx > 0)
                    {
                        if (nums[m_idx] == nums[m_idx-1])
                            leftest_idx = --m_idx;
                        else{
                            leftest_idx = m_idx;
                            break;
                        }
                    }
                    while (idx < n-1)
                    {
                        if (nums[idx] == nums[idx + 1])
                            rightest_idx = ++idx;
                        else{
                            rightest_idx = idx;
                            break;
                            }
                    }
                }
                res = {leftest_idx, rightest_idx};
            }
        }
        return res;
    }
    //Binary search method.
    int binarySearch(vector<int> &nums, int s, int e, int target){
        if(s >= e) {
            if(nums[s] == target) return s;
            else return -1;
        }
        int m = (s+e)/2;
        if(target == nums[m]) return m;
        else if(target < nums[m]) return binarySearch(nums, s, m-1, target);
        else return binarySearch(nums, m+1, e, target);
    }
};

