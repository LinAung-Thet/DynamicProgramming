// https://leetcode.com/problems/word-break/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string is always segmentable

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// Test cases
int main() {
    Solution solution;
    string s;
    vector<string> wordDict;

    cout << "Test case 1" << endl;
    s = "leetcode";
    wordDict = {"leet", "code"};
    cout << "Expected : true" << endl;
    cout << "Result   : " <<  (solution.wordBreak(s, wordDict) ? "true" : "false") << endl << endl;

    cout << "Test case 2" << endl;
    s = "applepenapple";
    wordDict = {"apple","pen"};
    cout << "Expected : true" << endl;
    cout << "Result   : " <<  (solution.wordBreak(s, wordDict) ? "true" : "false") << endl << endl;

    cout << "Test case 3" << endl;
    s = "catsandog";
    wordDict = {"cats","dog","sand","and","cat"};
    cout << "Expected : false" << endl;
    cout << "Result   : " <<  (solution.wordBreak(s, wordDict) ? "true" : "false") << endl << endl;

    return 0;
}