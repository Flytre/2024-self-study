#include <iostream>
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
    long long numberOfRightTriangles(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        long long ret = 0;
        vector<int> row_ones(n, 0);
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                row_ones[r] += grid[r][c] == 1 ? 1 : 0;

        for (int c = m - 1; c >= 0; c--) {
            int col_ones = 0;
            long long sum = 0;
            for (int r = 0; r < n; r++) {
                if (grid[r][c] == 1) {
                    col_ones++;
                    sum += row_ones[r] - 1;
                }
            }
            ret += col_ones <= 1 ? 0 : (sum * ((col_ones) - 1));
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 0},
                                {0, 1},
                                {1, 1}};
    long long result = sol.numberOfRightTriangles(grid);
    cout << "Number of right triangles: " << result << endl;
    return 0;
}