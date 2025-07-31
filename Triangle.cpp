// https://leetcode.com/problems/triangle/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];  // Start from the bottom row

        // Move upward row by row
        for (int row = n - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                dp[i] = triangle[row][i] + min(dp[i], dp[i + 1]);
            }
        }

        return dp[0];  // Top of triangle now contains the minimum path sum
    }
};

// Test cases
int main() {
    Solution solution;
    vector<vector<int>> triangle;

    cout << "Test case 1" << endl;
    triangle = {{2},{3,4},{6,5,7}};
    cout << "Expected : 10" << endl;
    cout << "Result   : " << solution.minimumTotal(triangle) << endl << endl;

    cout << "Test case 2" << endl;
    triangle = {{-10}};
    cout << "Expected : -10" << endl;
    cout << "Result   : " << solution.minimumTotal(triangle) << endl << endl;

    cout << "Test case 1" << endl;
    triangle = {{-1},{2,3},{1,-1,-3}};
    cout << "Expected : -1" << endl;
    cout << "Result   : " << solution.minimumTotal(triangle) << endl << endl;

    return 0;
}