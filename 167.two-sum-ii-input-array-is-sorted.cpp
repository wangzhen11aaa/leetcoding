/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.48%)
 * Likes:    1107
 * Dislikes: 456
 * Total Accepted:    296.9K
 * Total Submissions: 576.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int size = numbers.size();
//         if(size == 2) return {1,2};
//         vector<int> res{};
//         for(int i = 0; i< size - 1; i++){
//             int a = numbers[i];
//             int b = target - a;
//             if(a > target) break;
//             for(int j = i + 1; j < size; j++){
//                 if(numbers[j] < b) continue;
//                 else if(numbers[j] == b) {res.push_back(i)+1; res.push_back(j+1); return res;}
//                 else break;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start < end){
            if(numbers[start] + numbers[end] > target){
                end--;
            }else if(numbers[start] + numbers[end] < target){
                start++;
            }else {
                break;
            } 
        }
        return {start + 1, end + 1};
    }
}; 
// @lc code=end

