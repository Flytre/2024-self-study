
#include <iostream>
#include <set>
#include <map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        vector<int> latest_pair(2003, 1);
        for (auto &pair: pairs)
            latest_pair[pair[1] + 1002] = max(latest_pair[pair[1] + 1002], pair[0] + 1002);
        vector<int> dp(2003, -1);
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[latest_pair[i] - 1] + 1);
        }
        return dp[2002];
    }
};

int main() {
    vector<vector<int>> pairs = {{-1000, 2}};
    Solution sol;
    cout << sol.findLongestChain(pairs);
}