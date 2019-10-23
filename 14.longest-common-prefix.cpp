/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.01%)
 * Likes:    1576
 * Dislikes: 1440
 * Total Accepted:    530.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        string res = "";
        unsigned int  min_length = INT_MAX;
        int min_str_pos;
        // Find the string whoes length is the minimum.
        for(int i = 0; i < n -1; i++){
            int min_length_ = min_length;
            min_length = min_length < strs[i].length()?min_length:strs[i].length();
            if(min_length != min_length_)min_str_pos = i;
        }
        for(int i = 0; i < min_length; i++){
            char element_to_compare = strs[min_str_pos][i];
            for(int j = 0; j < n; j++){
                if(j == min_str_pos) continue;
                if(strs[j][i] != element_to_compare)
                    return res;
            }
            res+=element_to_compare;
        }
        return res;
    }
};

