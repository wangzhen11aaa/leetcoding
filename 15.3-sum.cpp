/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.58%)
 * Likes:    4341
 * Dislikes: 497
 * Total Accepted:    622.9K
 * Total Submissions: 2.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // The results must not contain duplicate tripliets.
//         unordered_set<int> s(nums.begin(), nums.end());
//         set<vector<int>> res;
//         sort(nums.begin(), nums.end());
//         int i, j;
//         for(i = 0; i < nums.size(); i++) {
//             for(j = i + 1; j < nums.size(); j++){
//                 if(s.find(0 - nums[i] - nums[j]) != s.end() && (nums[j]){
//                     vector<int> tmp = {nums[i], nums[j], 0-nums[i]-nums[j]};
//                     res.emplace(tmp);
//                 }
//             }
//         }
//     vector<vector<int>> _res(res.begin(), res.end());
//     return _res;
//     }
// };
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        // For all possible number, from the smallest to the (n-2)th position number,
        // (These can simplify the question, for we fix one direction.)
        //. Check all other combinations.
        for(int i=0;i<n-2;i++){
               if(i>0 && (nums[i]==nums[i-1]) )continue;
               int l=i+1, r= n-1;
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   if(sum<0) l++;
                   else if(sum>0)r--;
                   else {
                       res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                       //If we encounter same number, filter it.
                       while(l+1<r && nums[l]==nums[l+1])l++;
                       while(l<r-1 && nums[r]==nums[r-1]) r--;
                       l++; r--;
                   }
               }
        }
        return res;
    }
};
