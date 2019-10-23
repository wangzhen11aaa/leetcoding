/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (46.17%)
 * Likes:    3792
 * Dislikes: 466
 * Total Accepted:    431.1K
 * Total Submissions: 931.6K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution {
public:
    //Start from the right and left position.
    // Get the capacity between longest distance as the maximum value, then make these two indexes
    // approach towards each other. If we reserve larger height and move the other
    // side.
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        unsigned int max_capacity = min(height[i], height[j]) * (j - i);
        for(; i != j;){
            // height[i] >= height[j]
            if(height[i] - height[j] >= 0) j--;
            else i++;
            if(max_capacity < min(height[i], height[j]) * (j - i)) max_capacity = min(height[i], height[j]) * (j - i);

        }
        return max_capacity;
    }
};

