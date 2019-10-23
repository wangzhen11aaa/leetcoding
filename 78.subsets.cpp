/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (54.52%)
 * Likes:    2269
 * Dislikes: 56
 * Total Accepted:    407.7K
 * Total Submissions: 744.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int t = 0;
        for(int i=0; i<n; i++){
            t+=1<<i;
        }
        vector<vector<int>> res;
        while (t >= 0)
        {
            vector<int> tmp_res;
            for (int i = 0; i < n; i++)
            {
                if(t&(1<<i)) tmp_res.push_back(nums[i]);
            }
            res.push_back(tmp_res);
            t--;
        }
        return res;
    }
};

