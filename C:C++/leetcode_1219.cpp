#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int ret = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++)
                ret = max(ret, dfs(grid, r, c));
        }
        return ret;
    }

    int dfs(vv<int> &grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return 0;
        if (grid[r][c] == 0)
            return 0;

        int g = grid[r][c];
        int mx = 0;
        grid[r][c] = 0;

        for (int i = 0; i < 4; i++)
            mx = max(mx, dfs(grid, r + dr[i], c + dc[i]));

        grid[r][c] = g;
        return g + mx;
    }

private:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
};

int main() {
    Solution sol;

}