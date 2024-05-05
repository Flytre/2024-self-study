//
// Created by Aaron Rahman on 4/3/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <queue>
#include <vector>

#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSpaceWastedKResizing(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int dp[200][200];
        memset(dp, -1, sizeof(dp));
        int ret = min_partition(nums, 0, k, dp) - sum;
        return ret;
    }

    int min_partition(vector<int> &nums, int i, int k, int dp[200][200]) {
        if (i == nums.size()) return 0;
        if (k == -1) return 200 * 10000000 + 1;
        if (dp[i][k] != -1) return dp[i][k];
        int ret = 200 * 1000000 + 1;
        int max_val = nums[i];
        for (int j = i; j < nums.size(); j++) {
            max_val = max(max_val, nums[j]);
            ret = min(ret, min_partition(nums, j + 1, k - 1, dp) + max_val * (j - i + 1));
        }
        return dp[i][k] = ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums{823928,975967,995846,998485,999437,999889,999945,999988,999991,999999,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000};
    cout << sol.minSpaceWastedKResizing(nums, 86);
}
