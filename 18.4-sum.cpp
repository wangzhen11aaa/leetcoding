/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.29%)
 * Likes:    1223
 * Dislikes: 243
 * Total Accepted:    257.3K
 * Total Submissions: 820.7K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    // Fix one dimension, simplify the problem to three-sum problem,
    // get target equals minus fixed element. (Time Limit Exceeded.)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        // First sort.
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        if (n < 4) return {};
        // Fix one dimension, then iterate i from [0,n-3), then we need to find the element
        // nums[i] + [nums...] = target. In other words, we need nums[...] = target - nums[i].
        // This problem becomes three-sum type.
        int i, j;
        // Three-sum problem, we also need fix one dimension.
        for (i = 0; i < n - 3; i++){
            // Filter this situation.
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            for(j = i + 1; j < n - 2; j++) {
                // May be we encounter the same number, we just continue, and modify the index.
                if ((j != i + 1) && nums[j] == nums[j - 1]) continue;
                int _target = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while(l < r){
                    if(l == r) break;
                    bool skip = false;
                    // May be we encounter the same number, we just continue, and modify the index.

                    if (l != j + 1 && nums[l] == nums[l - 1]) {l++; skip = true;}
                    if ((r != n - 1) && nums[r] == nums[r + 1]) {r--; skip = true;}
                    if(skip) continue;
                    if(nums[l] + nums[r] == _target){
                        // copy constructor
                        vector tmp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(tmp);
                        l++;
                        r--;
                    }
                    else if(nums[l] + nums[r] < _target) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};

