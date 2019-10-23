/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.28%)
 * Likes:    449
 * Dislikes: 1846
 * Total Accepted:    301.3K
 * Total Submissions: 932.7K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int last_word_length = 0;
        for(auto i = 0; i < length; i++){
            if(s[i] != ' ') last_word_length++;
            else last_word_length = 0;
        }
        return last_word_length;
    }
};
// @lc code=end

