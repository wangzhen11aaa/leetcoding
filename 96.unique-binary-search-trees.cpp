/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (47.58%)
 * Likes:    2072
 * Dislikes: 80
 * Total Accepted:    222.9K
 * Total Submissions: 465.2K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:

    // Dynamic Programing.
    int numTrees(int n) {
       // One node only generates uniq tree.
       vector<int> v(n+1, 0);
       v[0] = 1;
       for(auto i = 1; i <= n; i++){
           for(auto j = 1; j <= i; j++){
               // j is the root of current tree.
               v[i] += v[j-1] * v[i-j];
           }
       }
    return v[n];
    }
};

