//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <numeric>

using namespace std;


//NOT MY CODE
class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int n = nums.size();

        bool dp[1 << n];
        int total[1 << n];
        memset(dp, false, sizeof(dp));
        memset(total, 0, sizeof(total));
        dp[0] = true;

        int sum = 0;
        for (int num: nums)
            sum += num;
        sort(nums.begin(), nums.end());

        if (sum % k != 0)
            return false;
        sum /= k;
        if (nums[n - 1] > sum)
            return false;

        for (int i = 0; i < (1 << n); i++) {
            if (dp[i]) {
                for (int j = 0; j < n; j++) {
                    int appended = i | (1 << j);
                    if (appended != i) {
                        if (nums[j] <= (sum - (total[i] % sum))) {
                            dp[appended] = true;
                            total[appended] = nums[j] + total[i];
                        } else
                            break;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    cout << sol.canPartitionKSubsets(nums, 4);
}