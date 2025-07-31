// https://leetcode.com/problems/edit-distance/description/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize base cases
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;  // Deletion
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;  // Insertion

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed
                } else {
                    dp[i][j] = 1 + min({
                        static_cast<int>(dp[i - 1][j]),     // Delete
                        static_cast<int>(dp[i][j - 1]),     // Insert
                        static_cast<int>(dp[i - 1][j - 1])  // Replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};

// Test cases
int main(){
    Solution solution;
    string word1, word2;

    cout << "Test case 1" << endl;
    word1 = "horse";
    word2 = "ros";
    cout << "Expected : 3" << endl;
    cout << "Result   : " << solution.minDistance(word1, word2) << endl << endl;

    cout << "Test case 2" << endl;
    word1 = "intention";
    word2 = "execution";
    cout << "Expected : 5" << endl;
    cout << "Result   : " << solution.minDistance(word1, word2) << endl << endl;

    return 0;
}