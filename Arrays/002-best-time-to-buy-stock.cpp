// Problem: Best Time to Buy and Sell Stock
// LeetCode #121
// Difficulty: Easy
// Approach: Track minimum price + maximum profit
// Time Complexity: O(n)
// Date: July 2026

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
