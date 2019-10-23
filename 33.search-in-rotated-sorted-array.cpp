/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.10%)
 * Likes:    2834
 * Dislikes: 349
 * Total Accepted:    467.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

class Solution {
    public:
    int search(vector<int> nums, int target) {
        if(nums.size()==0) return -1;
        int l=0, r=nums.size()-1, m=0;
       // find out the index of the smallest element.
        while(l<r){
            m = (l+r)/2;
            if(nums[m] > nums[r]){
                l = m+1;
            }else{
                r = m;
            }
        }
        
       // since we now know the start, find out if the target is to left or right of start in the array.
        int s = l;
        l = 0; r = nums.size()-1;
        if(target >= nums[s] && target <= nums[r]){
            l = s;
        }else{
            r = s;
        }
        // the regular search.
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]==target) return m;
            else if(nums[m] > target) r = m-1;
            else l=m+1;
        }
        
        return -1;
    }
};
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         if(n == 0) return -1;
//         int l, r;
//         l = 0;
//         r = n - 1;
//         if(target > nums[r] && target < nums[l]) return -1;
//         if(target == nums[l]) return l;
//         if(target == nums[r]) return r;
//         // [1,2,7,(1),3,7] target 2. // No duplicated data exists.
//         // 1,x,x,7,0,x,x,x,5. //The whole array is not sorted. The array can not be 
//         // transferred to an sorted array with one step.
//         // while(l < r){
//         //     int mid = (l + r)/ 2;
//         //     // Data fault is at some position between [mid+1, n-1]
//         //     if (nums[mid] >= nums[r]){
              
//         //     }else{
//         //         // target may be in [mid+1, n-1]
//         //     }
//         // } 
//         //First we need to find this pivot. binary search.
//         // 3,4,5,6,1,2
//         while(l < r){
//             int mid = (l + r) / 2;
//             // No duplicated data, so nums must be greater or smaller with the other.
//             if(nums[mid] < nums[r]){
//                 r = mid;
//             }else{
//                 l = mid + 1;
//             }
//         }
//         int pivot_pos = l;
//         while()

//     }
// };

