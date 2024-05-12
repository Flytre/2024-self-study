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
    bool satisfiesConditions(vector<vector<int>> &grid) {
        for (int c = 0; c < grid[0].size(); c++) {
            int num = grid[0][c];
            for (int r = 1; r < grid.size(); r++) {
                if (grid[r][c] != num)
                    return false;
            }
        }
        int prev = -1;
        for (int cval : grid[0]) {
            if (cval == prev)
                return false;
            prev = cval;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> grid{{1}, {2}, {3}};
    Solution sol;
    cout << sol.satisfiesConditions(grid);
}