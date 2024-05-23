#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

bool retains_beauty(vector<int> &nums, int k, int old_mask, int idx) {
    for (int i = 0; i < 20; i++) {
        if (((old_mask >> i) & 1) && abs(nums[idx] - nums[i]) == k)
            return false;
    }
    return true;
}


class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        int ctr = 0;
        auto beauty = vector<bool>(1 << nums.size(), false);
        beauty[0] = true;
        for (int i = 1; i < 1 << nums.size(); i++) {
            int leftmost_one = 31 - __builtin_clz(i);
            int prev = i & ((1 << leftmost_one) - 1); //number with leftmost 1 removed
            ctr += beauty[i] = beauty[prev] && retains_beauty(nums, k, prev, leftmost_one);
        }
        return ctr;
    }
};

int main() {
    vi nums = {1,3,4};
    Solution sol;
    cout << sol.beautifulSubsets(nums, 2);
}