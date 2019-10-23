/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.08%)
 * Likes:    4822
 * Dislikes: 691
 * Total Accepted:    487.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), l = 0, r = m;
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        while (l <= r){
            // i: index of the left array. array of the right array. Try to split and find the i.
            // A[0], A[1], ..., A[i - 1] | A[i], A[i + 1], ..., A[m - 1]
            // B[0], B[1], ..., B[j - 1] | B[j], B[j + 1], ..., B[n - 1]
            // Ensure (1) i + j = n  + m - i - j : left Parts numbers == right parts numbers
            // Ensure (2) A[i - 1] <= B[j] and B[j - 1] <= A[i]

            int i = (l + r) / 2, j = (m + n + 1) / 2 - i;

            if(i && nums1[i - 1] > nums2[j]){
                r = i - 1;
            }else if(i < m && nums2[j - 1] > nums1[i]){
                l = i + 1;
            }// Get the right split point, calculate the median.
            else {
                // the max value of the left parts
                // If i == 0 meaning that any element in A array is greater than B's, then the left max value comes from B.
                int lmax;
                if (i == 0){
                    lmax = nums2[j - 1];
                }else
                {
                    // if j == 0 meaning that any element in B is greater than A's, then the left max value comes from A.
                    if (j == 0){
                        lmax = nums1[i - 1];
                    }else
                    {
                        lmax = max(nums1[i - 1], nums2[j - 1]);
                    }
                }
                
                //int lmax = !i ? nums2[j - 1]: (!j ? nums1[i - 1]: max(nums1[ i - 1], nums2[j - 1]));
                 if ((m + n) % 2) {
                    return lmax;
                }
                // the min value of the right parts.
                // If i == m meaning that any element in A is less than B's, then all element from A is at left so right min value comes from B.
                int rmin;
                if(i == m){
                    rmin = nums2[j];
                }else{
                    if (j == n){
                        rmin = nums1[i];
                    }else{
                        rmin = min(nums1[i], nums2[j]);
                    }
                }
                //int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));
                return 0.5 * (lmax + rmin);
            }
        }
        return 0.0;
    }
};

