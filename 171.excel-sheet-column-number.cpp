/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (52.43%)
 * Likes:    662
 * Dislikes: 124
 * Total Accepted:    244.2K
 * Total Submissions: 464.6K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        const int N = 26;
        long coefficient = 1;
        int len = s.length();
        if(len == 0) return 0;
        else{
            long res = 0;
            for(int i = len - 1; i >= 0; i--){
                res += (s[i]-'A'+1)*coefficient;
                coefficient*=N;
            }
            return res;
        }     
    }
};
// @lc code=end

