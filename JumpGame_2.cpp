// https://leetcode.com/problems/jump-game-ii/description/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int farthest = 0;
        int end = 0;

        // We do not need to jump from the last index
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // If we reach the end of the current jump range
            if (i == end) {
                ++jumps;
                end = farthest;
            }
        }

        return jumps;
    }
};
// Test cases
int main(){
    Solution solution;
    vector<int> nums;
    int jumps;

    cout << "Test case 1" << endl;
    nums = {2,3,1,1,4};
    cout << "Expected : 2" << endl;
    cout << "Result   : " << solution.jump(nums) << endl << endl;

    cout << "Test case 2" << endl;
    nums = {2,3,0,1,4};
    cout << "Expected : 2" << endl;
    cout << "Result   : " << solution.jump(nums) << endl << endl;

    return 0;
}