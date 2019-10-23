/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (44.51%)
 * Likes:    1600
 * Dislikes: 1365
 * Total Accepted:    660.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
    // It is hard for me to high-pos digit from integer.
    // It is easy to get low-pos digit via % operator.
    // x_nth*10^(n-1)+x_n-1*10^(n-2)+x_n-2*(10^n-3)+...+x_1*(10^(n-(n-1)-1))

    bool isPalindrome(int x) {
        // if(x < 0) return false;
        // if(x < 10) return true;
        // int digit_n = 0;
        // vector<int> digit_v;
        // do{
        //     digit_v.push_back(x%10);
        //     digit_n++;
        // }while(x/=10);
        // int l, r;
        // for(l=0, r=digit_n-1; l<=r; l++, r--){
        //     if(digit_v[l]!=digit_v[r]) return false;
        // }
        // return true;

        if(x<0) return false;
        if(x<10) return true;
        int origin_x = x;
        unsigned int sum = 0;
        do{
            sum = sum*10+x%10;
        }while(x/=10);
        return sum==origin_x?true:false;
    }
};

