/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (34.96%)
 * Likes:    1365
 * Dislikes: 57
 * Total Accepted:    169.1K
 * Total Submissions: 483.6K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
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
// class Solution {
// public:
//     // Get maximum profit under one transaction.
//     // Get maximum profit under two transactions.
//     int maxProfit(vector<int>& prices) {
//         // Get maximum profit under one transaction.
//         int size = prices.size();
//         if(size <= 1) return 0;
//         // maximum profit one transaction.
//         int max_profit_one_step = 0;
//         int current_best_buy_price = prices[0];
//         for(int i = 1; i < size; i++){
//             if(current_best_buy_price > prices[i]) current_best_buy_price = prices[i];
//             else{
//                 if(current_best_buy_price < prices[i]) {
//                     int tmp_profit = prices[i] - current_best_buy_price;
//                     if(max_profit_one_step < tmp_profit) {
//                         max_profit_one_step = tmp_profit; 
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> profit_range(3, {0,0});
//         current_best_buy_price = prices[0];
//         int current_max_profit_vector = 0;
//         for(int i = 1; i < size - 1; i++){
//             if(current_best_buy_price > prices[i]) current_best_buy_price = prices[i];
//             else{
//                 if(prices[i] <= prices[i+1]){
//                     continue;
//                 }else{
//                     current_max_profit_vector = {current_best_buy_price, prices[i] - current_best_buy_price};
//                     current_best_buy_price = prices[i];
//                     // maximum;
//                     if(current_max_profit > profit_range[1]){
//                         profit[0] = profit[1];
//                         profit[1] = current_max_profit;
//                     }else{
//                         if(current_max_profit > profit[0]){
//                             profit[0] = current_max_profit;
//                         }
//                     }
//                 }
//             } 
//         }
//         if (prices[size - 1] > prices[size - 2])
//         {
//             current_max_profit = prices[size - 1] - current_best_buy_price;
//             if (current_max_profit > profit[1])
//             {
//                 profit[0] = profit[1];
//                 profit[1] = current_max_profit;
//             }
//             else
//             {
//                 if (current_max_profit > profit[0])
//                 {
//                     profit[0] = current_max_profit;
//                 }
//             }
//         }
//         int max_profit_two_steps = 0;
//         for (int i = 0; i < 2; i++)
//         {
//             max_profit_two_steps += profit[i];
//         }
//         return max(max_profit_one_step, max_profit_two_steps);
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};
// @lc code=end

