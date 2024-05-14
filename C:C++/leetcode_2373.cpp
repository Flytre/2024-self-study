#include <iostream>
#include <set>
#include <map>
#include <stack>

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
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        vector<vector<int>> ret(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid.size() - 1; c++) {
                ret[r - 1][c - 1] = max_around(grid, r, c);
            }
        }
        return ret;
    }

    int max_around(vector<vector<int>> &grid, int r, int c) {
        int m = 0;
        for (int r1 = r - 1; r1 <= r + 1; r1++)
            for (int c1 = c - 1; c1 <= c + 1; c1++) {
                m = max(m, grid[r1][c1]);
            }
        return m;
    }
};