/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (48.35%)
 * Likes:    3210
 * Dislikes: 145
 * Total Accepted:    603K
 * Total Submissions: 1.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) {return 0;}
        unsigned int max_profit = 0;
        int current_best_buy_price = prices[0];
        int tmp_profit;
        for(int i = 1; i < size - 1; i++){
            if(current_best_buy_price > prices[i]) current_best_buy_price = prices[i];
            else{
                if(prices[i] < prices[i+1]) continue;
                else{
                    tmp_profit = prices[i] - current_best_buy_price;
                    max_profit = (max_profit > tmp_profit? max_profit:tmp_profit);
                }
                //max_profit = (max_profit > prices[i] - current_best_buy_price? max_profit:prices[i]-current_best_buy_price);
            }
        }
        if(prices[size-1]>=prices[size-2]){
            max_profit = (max_profit > prices[size-1] - current_best_buy_price? max_profit:prices[size-1]-current_best_buy_price);
        }
        return max_profit;
    }
};
// @lc code=end

