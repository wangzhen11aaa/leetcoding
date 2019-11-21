/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (57.55%)
 * Likes:    2046
 * Dislikes: 134
 * Total Accepted:    272.2K
 * Total Submissions: 473K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    using pair=std::pair<int,int>;
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int len = nums.size();
        // O(n) space complexity.
        std::map<int, int> mapping;
        for(int i = 0; i < len; i++){
            if(mapping.find(nums[i])!=mapping.end()){
                mapping[nums[i]]++;
            }else{
                mapping.insert(std::pair<int,int>(nums[i], 0));
            }
        }
        std::vector<std::pair<int, int>> vec;
        std::copy(mapping.begin(), mapping.end(), std::back_inserter<std::vector<pair>>(vec));
        std::sort(vec.begin(), vec.end(),[](const pair &l ,const pair &r){
            if(l.second != r.second) return l.second > r.second;
            return l.first < r.first;
        });
        
        std::vector<int> res;
        for(int i = 0; i<k; i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};
// @lc code=end

