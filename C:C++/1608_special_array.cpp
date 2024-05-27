#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <cmath>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

template<typename T>
using vvv = vector<vector<vector<T>>>;

class Solution {
public:
    int specialArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            auto it = lower_bound(nums.begin(), nums.end(), i);
            if(it - nums.begin() == nums.size() - i) return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vi inp = {4};
    cout << sol.specialArray(inp);
}