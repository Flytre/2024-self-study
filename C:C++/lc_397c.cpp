#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class Solution {
public:
    int maxScore(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        long long res = INT_MIN;
        queue<pair<int, int>> q;
        vector<vector<long long>> bgr(n, vector<long long>(m, INT_MIN));
        for (int c = m - 1; c >= 0; c--) {
            for (int r = n - 1; r >= 0; r--) {
                long long bgr_curr = INT_MIN;
                if (r < n - 1)
                    bgr_curr = max(bgr_curr, bgr[r + 1][c]);
                if (c < m - 1)
                    bgr_curr = max(bgr_curr, bgr[r][c + 1]);
                bgr[r][c] = max(bgr_curr, (long long) grid[r][c]);
                res = max(res, bgr_curr - grid[r][c]);
            }
        }
        return (int) res;

    }
};

int main() {
    vector<vector<int>> d = {{9, 5, 7,  3},
                             {8, 9, 6,  1},
                             {6, 7, 14, 3},
                             {2, 5, 3,  1}};
    Solution sol;
    cout << sol.maxScore(d);
}