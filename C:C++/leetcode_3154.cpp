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


int nCr(int n, int r) {
    if (r > n - r)
        r = n - r; // because C(n, r) == C(n, n-r)
    ll res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return (int)res;
}

class Solution {
public:
    int waysToReachStair(int k) {
        ll ctr = (k == 0 || k == 1); //0 jumps
        ll stair_sum = 1;
        ll one = 1;
        for (int i = 1; i <= 29; i++) {
            stair_sum += one << (i - 1); //sum of # of jumps made
            ll needed_minuses = stair_sum - k;
            if (stair_sum >= k && needed_minuses <= i + 1) {
                ctr += nCr(i + 1, (int) needed_minuses);
            }
        }
        return (int) ctr;
    }
};

int main() {
    Solution sol;
    cout << sol.waysToReachStair(0);
}