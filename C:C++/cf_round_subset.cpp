#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <string>
//Partial solution: need a sortring algorithm i wont make cuz this approach is wrong
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

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> tens(n, 0); //values within [0, 18]
    vector<int> two_fives(n, 0); //values within (-64, 64)
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] % 10 == 0) tens[i]++, nums[i] /= 10;
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] % 5 == 0) two_fives[i]++, nums[i] /= 5;
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] % 2 == 0) two_fives[i]--, nums[i] /= 2;
    const int OFFSET = 64;
    vvv<int> dp = vvv<int>(n + 1, vv<int>(k + 1, vi(2 * OFFSET + 1, INT_MIN))); //[max idx] x [nums used] x [offset]
    for (int idx = 0; idx <= n; idx++) {
        dp[idx][0][OFFSET] = 0;
    }
    int ans = 0;
    for (int idx = 1; idx <= n; idx++) {
        for (int used = 1; used <= k; used++) {
            for (int offset = -OFFSET; offset <= OFFSET; offset++) {
                int prev_offset = offset - two_fives[idx - 1];
                if (abs(prev_offset) <= OFFSET && used > 0) {
                    int offset_contribution = prev_offset * offset < 0 ? abs(prev_offset) : max(0, abs(prev_offset) - abs(offset));
                    dp[idx][used][offset + OFFSET] = max(dp[idx][used][offset + OFFSET],
                                                                        dp[idx - 1][used - 1][prev_offset +
                                                                                              OFFSET] + tens[idx - 1] +
                                                                        offset_contribution);
                }
                dp[idx][used][offset + OFFSET] = max(dp[idx][used][offset + OFFSET],
                                                     dp[idx - 1][used][offset + OFFSET]);
                dp[idx][used][offset + OFFSET] = max(dp[idx][used][offset + OFFSET],
                                                     dp[idx][used - 1][offset + OFFSET]);
                ans = max(ans, dp[idx][used][offset + OFFSET]);
            }
        }
    }
    cout << ans << endl;
}