/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.46%)
 * Likes:    2398
 * Dislikes: 3701
 * Total Accepted:    785K
 * Total Submissions: 3.1M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
    long long ret = 0;
    do{
        ret = 10 * ret + x % 10;
    }while (x /= 10);
    return (ret > INT_MAX || ret < INT_MIN)?0:int(ret);
    }
    //     // digit vector used to store the digit.
    //     vector<int> digit;
    //     int positive_flag = x > 0?1:-1;
    //     int u_x = x*positive_flag;
    //     while(u_x){
    //         digit.push_back(u_x%10);
    //         u_x = u_x / 10;
    //     }
    //     int ret_x;
    //     auto n = digit.size();
    //     int i = 0;
    //     while(n>=0){
    //         ret_x += pow(10,(--n))* digit[i++];
    //     }
    // }
};

