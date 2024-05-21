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
    int subsetXORSum(vector<int> &&nums) {
        int sum = 0;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int csum = 0, j = 0;
            while (j < 12) {
                if ((i >> j) & 1)
                    csum = csum xor nums[j];
                j++;
            }
            sum += csum;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    cout << sol.subsetXORSum({3,4,5,6,7,8});
}