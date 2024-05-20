#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <numeric>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

class Solution {
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        vector<ll> xor_diff(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            xor_diff[i] = (nums[i] ^ k) - nums[i];
        }
        ll sum = accumulate(nums.begin(), nums.end(), 0L);
        sort(xor_diff.begin(), xor_diff.end());
        int ptr = nums.size() - 2;
        while (ptr >= 0 && xor_diff[ptr] + xor_diff[ptr + 1] > 0) {
            sum += xor_diff[ptr] + xor_diff[ptr + 1];
            ptr -= 2;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vi nums = {1, 2, 1};
    vv<int> edges = {};
    int k = 3;
    sol.maximumValueSum(nums, k, edges);
}