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
    int matrixScore(vector<vector<int>> &grid) {
        vector<bool> rows(grid.size(), false);
        vector<bool> cols(grid[0].size(), false);
        for (char r = 0; r < rows.size(); r++)
            if (grid[r][0] == 0)
                rows[r] = true;
        for (char c = 0; c < cols.size(); c++) {
            short zero_ct = 0;
            for (char r = 0; r < rows.size(); r++) {
                if (!((grid[r][c] + rows[r]) % 2))
                    zero_ct++;
            }
            if (zero_ct > rows.size() / 2)
                cols[c] = true;
        }
        int ret = 0;
        for (int r = 0; r < rows.size(); r++) {
            for (int c = 0; c < cols.size(); c++) {
                ret += ((grid[r][c] + rows[r] + cols[c]) % 2) << (cols.size() - 1 - c);
            }
        }
        return ret;
    }
};

int main() {
    vector<vi> grid = {{0, 0, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 0}};
    Solution sol;
    cout << sol.matrixScore(grid) << endl;
}