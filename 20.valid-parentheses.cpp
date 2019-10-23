/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.08%)
 * Likes:    3287
 * Dislikes: 154
 * Total Accepted:    677.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        int n = s.length(); 
        if (n == 0) return true;
        if (n % 2)
            return false;
        vector<char> stack(n/2+1);
        int i = 0;
        for(int j = 0; j < n && i < n/2+1; j++){
            if(i==0){stack[i++]=s[j];}
            else if(stack[i-1]=='(' && s[j] == ')' || stack[i-1] == '[' && s[j] == ']' || stack[i-1] == '{' && s[j] == '}') i--;
            else stack[i++]=s[j];
        }
        return (i==0?true:false);
    }
};

