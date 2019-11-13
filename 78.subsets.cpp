/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
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
// @lc code=end

