// https://leetcode.com/problems/jump-game/description/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestEnd = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > farthestEnd) return false;

            farthestEnd = max(farthestEnd, i + nums[i]);
        }
        return true;
    }
};

// Test cases
int main() {
    Solution solution;
    vector<int> nums;
    
    cout << "Test case 1" << endl;
    nums = {2,3,1,1,4};
    cout << "Expected : true" << endl;
    cout << "Result   : " << (solution.canJump(nums) ? "true" : "false") << endl << endl;
    
    cout << "Test case 2" << endl;
    nums = {3,2,1,0,4};
    cout << "Expected : false" << endl;
    cout << "Result   : " << (solution.canJump(nums) ? "true" : "false") << endl << endl;

    return 0;
}