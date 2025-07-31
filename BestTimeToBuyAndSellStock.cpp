// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
#include<limits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> prices;

    cout << "Test case 1" << endl;
    prices = {7,1,5,3,6,4};
    cout << "Expected : 5" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    cout << "Test case 2" << endl;
    prices = {7,6,4,3,1};
    cout << "Expected : 0" << endl;
    cout << "Result   : " << solution.maxProfit(prices) << endl << endl;

    return 0;
}