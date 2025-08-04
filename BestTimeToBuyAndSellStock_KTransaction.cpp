// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
#include<limits>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;

        // Optimize for very large k: equivalent to unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i)
                profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }

        // DP table: dp[t][d] = max profit with at most t transactions until day d
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int d = 1; d < n; ++d) {
                dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
            }
        }

        return dp[k][n - 1];
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> prices;
    int k = 3;

    // cout << "Test case 1" << endl;
    // prices = {3,3,5,0,0,3,1,4};
    // cout << "Expected : 8" << endl;
    // cout << "Result   : " << solution.maxProfit(3, prices) << endl << endl;

    // cout << "Test case 2" << endl;
    // prices = {1,2,3,4,5};
    // cout << "Expected : 4" << endl;
    // cout << "Result   : " << solution.maxProfit(3, prices) << endl << endl;

    // cout << "Test case 3" << endl;
    // prices = {7,6,4,3,1};
    // cout << "Expected : 0" << endl;
    // cout << "Result   : " << solution.maxProfit(3, prices) << endl << endl;

    cout << "Test case 4" << endl;
    prices = {1,5,3,8,2,9,0,1};
    cout << "Prices   : 1,5,3,8,2,9,0,1" << endl;
    cout << "Expected : 16" << endl;
    cout << "Result   : " << solution.maxProfit(3, prices) << endl << endl;

    return 0;
}