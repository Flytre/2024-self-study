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
    bool isArraySpecial(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] % 2 == nums[i-1] % 2)
                return false;
        }
        return true;
    }
};