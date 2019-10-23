/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.52%)
 * Likes:    4275
 * Dislikes: 80
 * Total Accepted:    337.3K
 * Total Submissions: 757.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
// For each i in the x coordinate，if it is higher than environments(left and right),
// the i can not store water. Else, we should find the highest left and right.
// We can define L[] and R[] to the highest left and highest right.
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0; 
        int n = height.size();
        vector<int> L(n, 0);
        vector<int> R(n, 0);
        // L[i] stores the largest number from 0 to i.
        int max_height=height[0];
        for(int i=1; i<n-1; i++){
            max_height = max_height>height[i]?max_height:height[i];
            L[i]=max_height;
        }
        max_height=height[n-1];
        for(int i=n-2;i>0;i--){
            max_height = max_height>height[i]?max_height:height[i];
            R[i]=max_height;
        }
        int sum=0;
        for(int i=1; i<n-1; i++){
            int environment_height = L[i]>=R[i]?R[i]:L[i];
            sum+=abs(height[i]-environment_height);
        }
        return sum;
    }
};

