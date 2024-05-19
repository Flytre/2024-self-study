#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <unordered_map>

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
    long long sumDigitDifferences(vector<int> &nums) {
        ll sum = 0;
        while (nums[0] > 0) {
            unordered_map<int, ll> freq = {};
            for (int i = 0; i < nums.size(); i++) {
                freq[nums[i] % 10]++;
                nums[i] /= 10;
            }
            ll tally = 0;
            for (int i = 0; i < 10; i++) {
                sum += freq[i] * (nums.size() - tally - freq[i]);
                tally += freq[i];
            }
        }
        return sum;
    }
};

int main() {
    vi nums = {1, 1, 1, 1, 2, 2, 2, 3, 3};
    Solution sol;
    cout << sol.sumDigitDifferences(nums);
}