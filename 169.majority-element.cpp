/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.33%)
 * Likes:    2024
 * Dislikes: 178
 * Total Accepted:    446.3K
 * Total Submissions: 820K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       map<int, int> res;
       for(int i = 0; i < nums.size(); i++){
           if(res.find(nums[i])==res.end()){
               //cout << "nums[" << i << "] : " << nums[i] << endl; 
               res[nums[i]] = 1;
           }
           res[nums[i]] = res[nums[i]] + 1;
           //cout << nums[i] << ": " << res[nums[i]];

       }
       map<int,int>::iterator max_it = res.begin();
    
       //for(map<int,int>::iterator map_it = res.begin(); map_it != res.end(); ++map_it){
        for(auto const map_it: res){
           if(max_it->second < map_it->second){
               max_it = map_it;
           }
       }
       return max_it->first;
    }
};
// @lc code=end

