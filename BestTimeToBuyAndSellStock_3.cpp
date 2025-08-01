// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
#include<limits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> left(n, 0);   // Max profit if we sell on or before day i
        vector<int> right(n, 0);  // Max profit if we buy on or after day i

        // Left sweep: best single transaction ending by day i
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        // Right sweep: best single transaction starting from day i
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        // Combine both sweeps: best split point for two transactions
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> prices;

    cout << "Test case 1" << endl;
    prices = {3,3,5,0,0,3,1,4};
    cout << "Expected : 6" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    cout << "Test case 2" << endl;
    prices = {1,2,3,4,5};
    cout << "Expected : 4" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    cout << "Test case 3" << endl;
    prices = {7,6,4,3,1};
    cout << "Expected : 0" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    cout << "Test case 4" << endl;
    prices = {1,5,3,8,2,9};
    cout << "Expected : 14" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    return 0;
}