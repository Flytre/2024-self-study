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

class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        vi max_special(nums.size(), 0);

        int idx = 0;
        for (int end = 1; end < nums.size(); end++) {
            if (nums[end - 1] % 2 == nums[end] % 2) {
                while (idx < end)
                    max_special[idx++] = end - 1;
            }
        }
        while (idx < nums.size())
            max_special[idx++] = nums.size();

        vector<bool> ret = {};
        for (auto &query: queries) {
            ret.push_back(max_special[query[0]] >= query[1]);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 1};
    vector<vector<int>> b = {{0, 1}};
    cout << sol.isArraySpecial(a, b)[0] << endl;
}