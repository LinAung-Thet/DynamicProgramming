// https://leetcode.com/problems/palindrome-partitioning-ii/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> cuts(n, 0);

        for (int i = 0; i < n; ++i) {
            int minCut = i;  // Worst case: cut before every character
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    minCut = (j == 0) ? 0 : min(minCut, cuts[j - 1] + 1);
                }
            }
            cuts[i] = minCut;
        }

        return cuts[n - 1];
    }
};

// Test cases
int main()
{
    Solution solution;
    string input;
    int results;

    cout << "Test case 1" << endl;
    input = "aab";
    cout << "Expected : 1" << endl;
    results = solution.minCut(input);
    cout << "Result   : " << results << endl << endl;
    
    cout << "Test case 2" << endl;
    input = "a";
    cout << "Expected : 0" << endl;
    results = solution.minCut(input);
    cout << "Result   : " << results << endl << endl;
    
    cout << "Test case 3" << endl;
    input = "ab";
    cout << "Expected : 1" << endl;
    results = solution.minCut(input);
    cout << "Result   : " << results << endl << endl;

    return 0;
}