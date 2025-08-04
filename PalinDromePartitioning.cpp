// https://leetcode.com/problems/palindrome-partitioning/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

// Test cases
int main()
{
    Solution solution;
    string input;
    vector<vector<string>> results;

    // cout << "Test case 1" << endl;
    // input = "aab";
    // cout << "Expected : [[a a b][aa b]]" << endl;
    // results = solution.partition(input);
    // cout << "Result   : [";
    // for (auto result : results) {
    //     cout << "[";
    //     for (int i = 0; i < result.size(); ++i) {
    //         cout << result[i] << (i == result.size() - 1 ? "" : " ");
    //     }
    //     cout << "]";
    // }
    // cout << "]" << endl << endl;
    
    // cout << "Test case 2" << endl;
    // input = "a";
    // cout << "Expected : [[a]]" << endl;
    // results = solution.partition(input);
    // cout << "Result   : [";
    // for (auto result : results) {
    //     cout << "[";
    //     for (int i = 0; i < result.size(); ++i) {
    //         cout << result[i] << (i == result.size() - 1 ? "" : " ");
    //     }
    //     cout << "]";
    // }
    // cout << "]" << endl << endl;
    
    cout << "Test case 3" << endl;
    input = "abbcd";
    cout << "Expected : [[a b b c d] [a bb c d]]" << endl;
    results = solution.partition(input);
    cout << "Result   : [";
    for (auto result : results) {
        cout << "[";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << "] ";
    }
    cout << "]" << endl << endl;

    return 0;
}