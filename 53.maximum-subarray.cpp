/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.44%)
 * Likes:    5132
 * Dislikes: 198
 * Total Accepted:    635.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         // int local_sum = 0, global_max = INT_MIN;
//         // for (int num : nums) {
//         //     local_sum += num;
//         //     global_max = max(global_max, local_sum);
//         //     if (local_sum < 0) {
//         //         local_sum = 0;
//         //     }
//         // }
//         // return global_max;
        
//     }
// };
class Solution {
public:
    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];// Equals one value.
        }
        else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            cout << " lmx1: " << lmx1 << " lmx2 : " << lmx2 << endl;
            cout << " rmx1: " << rmx1 << " rmx2 : " << rmx2 << endl;
            mx = max(max(mx1, mx2), rmx1 + lmx2);//mx (largest sum of this subarray)
            lmx = max(lmx1, sum1 + lmx2);// lmx(largest sum starting from the left most element)
            rmx = max(rmx2, sum2 + rmx1);// rmx(largest sum ending with the right most element)
            cout << "l : " << l << " r: " << r << endl;
            sum = sum1 + sum2; // sum(the sum of the total subarray).
            cout << "mx : " << mx << " lmx : " << lmx << " rmx : " << rmx << " sum : " << sum;  
            cout << "sum1 : " << sum1 << " :sum2 : " << sum2;
        }
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int mx, lmx, rmx, sum;
        maxSubArray(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
        return mx;
    }
};
// @lc code=end

