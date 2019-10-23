/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.93%)
 * Likes:    2111
 * Dislikes: 669
 * Total Accepted:    264.7K
 * Total Submissions: 854.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
// class Solution {
// public:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
    // Use vector as bucket. index of vector as the digit number.
    // void nextPermutation(vector<int>& nums) {

    //     int n = nums.size();
    //     if(n < 2) return;
    //     vector<int> bucket(10, 0);
    //     int pivot_pos, pivot;
    //     int i;
    //     for (i = n - 1; i > 0; i--)
    //     {
    //         // count times of element.
    //         bucket[nums[i]]++;
    //         if (nums[i] > nums[i - 1])
    //             break;
    //     }
    //     if(i != 0){
    //         bucket[nums[i-1]]++;
    //     }else{
    //         bucket[nums[i]]++;
    //     }
    //     // The lowest number should be set.
    //     if(i==1){
    //         int _i = 0;
    //         for(int j = 1; j <= 9 && _i < n;){
    //             if(_i == 0){
    //                 if(bucket[j] == 0) j++;
    //                 else {
    //                     nums[_i++] = j;
    //                     bucket[j]--;
    //                     }
    //             }else{
    //                 if(bucket[0] != 0) {
    //                     nums[_i++] = 0;
    //                     bucket[0]--;
    //                 }else{
    //                     if(bucket[j] != 0){
    //                         nums[_i++] = j;
    //                         bucket[j]--;
    //                     }else j++;
    //                 }
    //             }
    //         }
    //     }
    //     pivot = (i == 0)?nums[i]:nums[i - 1];
    //     pivot_pos = i==0?i:i-1;
    //     bool found_flag = false;
    //     // find the number which is mimimum number greater than pivot.
    //     for(int v = pivot + 1; v<=9; v++){
    //         if(bucket[v] != 0){
    //             nums[pivot_pos] = v;
    //             bucket[v]--;
    //             break;
    //         }
    //     }
    //     if(!found_flag) return;
    //     for(int j = 0; j <= 9 && pivot_pos < n;){
    //         if(bucket[j] == 0) j++;
    //         else{
    //             nums[++pivot_pos] = j;
    //             bucket[j]--;
    //         }
    //     }
    // }
// };

