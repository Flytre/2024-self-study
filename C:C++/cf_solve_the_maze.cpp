#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool bounded(vv<char> &grid, int r, int c) {
    return 0 <= r && 0 <= c && r < grid.size() && c < grid[0].size();
}

bool can_replace(vv<char> &grid, int r, int c) {
    for (int i = 0; i < 4; i++)
        if (bounded(grid, r + dr[i], c + dc[i]) && grid[r + dr[i]][c + dc[i]] == 'B')
            return false;

    return true;
}

int ff(vv<char> &grid, int r, int c) {
    if (!bounded(grid, r, c) || grid[r][c] == '#' || grid[r][c] == 'v' || !can_replace(grid, r, c))
        return 0;
    int sum = grid[r][c] == 'G';
    if (can_replace(grid, r, c)) {
        grid[r][c] = 'v';
        for (int i = 0; i < 4; i++)
            sum += ff(grid, r + dr[i], c + dc[i]);
    } else {
        if (grid[r][c] == 'G')
            return -9999;
        else
            grid[r][c] = 'v';
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        auto grid = vv<char>(n, vector<char>(m, 'U'));
        char ch;
        int remaining = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++) {
                cin >> ch;
                remaining += ch == 'G';
                grid[r][c] = ch;
            }
        int x = ff(grid, n - 1, m - 1);
        if (x == remaining)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}