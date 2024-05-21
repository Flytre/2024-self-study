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
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.size() == 0) {
            sol.emplace_back(curr.rbegin(), curr.rend());
        } else {
            int last = nums[nums.size() - 1];
            nums.pop_back();
            subsets(nums);
            curr.push_back(last);
            subsets(nums);
            curr.pop_back();
            nums.push_back(last);
        }
        return sol;
    }

private:
    vv<int> sol = vv<int>();
    vi curr = vi();
};

int main() {
    vi nums = {1, 2, 3};
    Solution sol;
    auto ans = sol.subsets(nums);
    for (auto &vec: ans) {
        for (auto i: vec)
            cout << i << " ";
        cout << endl;
    }
}