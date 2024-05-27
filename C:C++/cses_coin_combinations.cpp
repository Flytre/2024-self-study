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

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;


int main() {
    int coin_types, desired_sum;
    cin >> coin_types >> desired_sum;
    vi coins(coin_types, 0);
    for (int i = 0; i < coin_types; i++)
        cin >> coins[i];
    vv<int> dp = vv<int>(desired_sum + 1, vi(coin_types, 0));
    dp[0][0] = 1;
    for (int sum = 0; sum <= desired_sum; sum++) {
        for (int idx = 0; idx < coin_types; idx++) {
            dp[sum][idx] += idx > 0 ? dp[sum][idx - 1] : 0; //not using this coin
            dp[sum][idx] += sum - coins[idx] >= 0 ? dp[sum - coins[idx]][idx] : 0; //using this coin 1+ times
            dp[sum][idx] %= 1'000'000'007;
        }
    }
    cout << dp[desired_sum][coin_types - 1] << endl;
}