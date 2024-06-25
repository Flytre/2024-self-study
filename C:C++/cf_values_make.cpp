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
    int coins[501];
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    //idx, sum value, possible sums
    bool dp[501][501][501];
    dp[0][0][0] = true;
    bool ans[501];
    for (int idx = 1; idx <= n; idx++)
        for (int val = 0; val <= k; val++) {
            if (coins[idx] >= val) {
                int old_val = val - coins[idx];
            }
        }
    int q = 0;
    for (int i = 0; i <= 500; i++)
        if (ans[i]) q++;
    cout << q << endl;
    for (int i = 0; i <= 500; i++)
        if (ans[i]) cout << i << " ";
}