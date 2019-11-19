/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (53.21%)
 * Likes:    1276
 * Dislikes: 1424
 * Total Accepted:    380.3K
 * Total Submissions: 714.5K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */


// @lc code=start
class Solution {
public:
    //change the code into dynamic program.
    int maxProfit(vector<int>& prices) {
    //     int length = prices.size();
    //     if(length <= 1) return 0;
    //     int best_buy_price = prices[0];
    //     int _max_profit = 0;
    //     int max_profit = 0;
    //     // last item in prices is useless.
    //     for(int i = 1; i < length - 1 ; i++){
    //         // It is the day to buy stock.
    //         if (best_buy_price > prices[i])
    //         {
    //             best_buy_price = prices[i];
    //         }
    //         else // It may be the day to sell.
    //         {
    //             if (prices[i] > prices[i + 1])
    //             {
    //                 max_profit += (prices[i] - best_buy_price);
    //                 _max_profit = 0;
    //                 best_buy_price = prices[i+1];
    //             }
    //         }
    //     }
    //     if(prices[length - 1] >= prices[length -2]) {
    //         max_profit += prices[length -1] - best_buy_price;
    //     }
    //     return max_profit;
        int states[2][2] = {INT_MIN, 0}; // 0: buy stock, 1: sell stock
        
        int len = prices.size(), cur=0, next = 1;
        for(int i = 0; i < len; i++){
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            swap(cur, next);
        }
        return states[cur][1];
    } 
};
// @lc code=end

