/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (53.08%)
 * Likes:    1411
 * Dislikes: 2828
 * Total Accepted:    475.8K
 * Total Submissions: 895.4K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    // When encounter the I,X,C, we need to check that whether this element will be combined as a number,
    // instead of only itself.
    
    int romanToInt(string s) {
        int n = s.length();
        int sum = 0;
        for(int i = 0; i<n;){
            if(s[i] == 'I'){
                // Let the iterate end.
                if(i+1 >= n) {sum += 1; break;}
                else{
                    if(s[i+1] == 'X') {sum+=9; i+=2;}
                    else if(s[i+1] == 'V') {sum += 4; i+=2;}
                    else {sum+=1; i++;}
                }
            }
            else if(s[i] == 'X'){
                if(i+1 >= n) {sum+=10; break;}
                else{
                    if(s[i+1] == 'L' ){sum+=40; i+=2;}
                    else if(s[i+1] == 'C') {sum+=90; i+=2;}
                    else{sum+=10; i++;}
                }
            }
            else if(s[i] == 'C'){
                if(i+1 >= n){ sum+=100; break;}
                else{
                    if(s[i+1]=='D'){sum+=400; i+=2;}
                    else if(s[i+1]=='M'){sum+=900;i+=2;}
                    else{sum+=100; i++;}
                }
            }
            else if(s[i]=='V') {sum+=5; i++;}
            else if(s[i]=='L') {sum+=50; i++;}
            else if(s[i]=='D') {sum+=500; i++;}
            else {sum+=1000;i++;}
        }
        return sum;
    }
};

