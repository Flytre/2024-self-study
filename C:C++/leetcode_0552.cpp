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
    int checkRecord(int n) {
        auto dp = vvv<ll>(n, vv<ll>(2, vll(3, 0)));
        dp[0][0][0] = 1; //present: day 1
        dp[0][0][1] = 1; //late: day 1
        dp[0][1][0] = 1; //absent: day 1
        for (int day = 1; day < n; day++) {
            //0 days late = present or absent today
            dp[day][0][0] = dp[day - 1][0][0] + dp[day - 1][0][1] + dp[day - 1][0][2];
            dp[day][1][0] = dp[day - 1][1][0] + dp[day - 1][1][1] + dp[day - 1][1][2]
                            + dp[day - 1][0][0] + dp[day - 1][0][1] + dp[day - 1][0][2];
            //late today
            for (int days_late = 1; days_late <= 2; days_late++)
                for (int absence = 0; absence <= 1; absence++)
                    dp[day][absence][days_late] = dp[day - 1][absence][days_late - 1];

            for (int late = 0; late <= 2; late++)
                for (int absence = 0; absence <= 1; absence++)
                    dp[day][absence][late] %= 1'000'000'007;
        }
        ll ways = 0;
        for (int late = 0; late <= 2; late++)
            for (int absence = 0; absence <= 1; absence++) {
                ways += dp[n - 1][absence][late];
            }
        return (int) (ways % 1'000'000'007);
    }
};

int main() {
    Solution sol;
    cout << sol.checkRecord(1);
}