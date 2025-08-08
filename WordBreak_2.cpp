// https://leetcode.com/problems/word-break-ii/description/?envType=problem-list-v2&envId=dynamic-programming

#include<vector>
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }

private:
    vector<string> dfs(const string& s, unordered_set<string>& dict) {
        if (s.empty()) return {""};

        vector<string> result;
        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> suffixes = dfs(s.substr(i), dict);
                for (const string& suffix : suffixes) {
                    string sentence = word + (suffix.empty() ? "" : " " + suffix);
                    result.push_back(sentence);
                }
            }
        }

        return result;
    }
};

//Test cases
int main() {
    Solution solution;
    string s;
    vector<string> result;
    vector<string> wordDict;

    cout << "Test case 1" << endl;
    s = "catsanddog";
    wordDict = {"cat","cats","and","sand","dog"};
    result = solution.wordBreak(s, wordDict);
    cout << "Expected : [cats and dog, cat sand dog]" << endl;
    cout << "Result   : [";
    for (auto sentence : result) {
        cout << sentence << ", ";
    }
    cout << "]" << endl << endl;

    cout << "Test case 2" << endl;
    s = "pineapplepenapple";
    wordDict = {"apple","pen","applepen","pine","pineapple"};
    result = solution.wordBreak(s, wordDict);
    cout << "Expected : [pine apple pen apple, pineapple pen apple, pine applepen apple]" << endl;
    cout << "Result   : [";
    for (auto sentence : result) {
        cout << sentence << ", ";
    }
    cout << "]" << endl << endl;

    cout << "Test case 3" << endl;
    s = "catsandog";
    wordDict = {"cats","dog","sand","and","cat"};
    result = solution.wordBreak(s, wordDict);
    cout << "Expected : []" << endl;
    cout << "Result   : [";
    for (auto sentence : result) {
        cout << sentence << ", ";
    }
    cout << "]" << endl << endl;

    return 0;
}
