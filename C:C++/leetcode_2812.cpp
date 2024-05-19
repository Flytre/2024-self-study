#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

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
    int maximumSafenessFactor(vv<int> &grid) {
        int n = grid.size();

        //precompute
        queue<pair<ii, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    q.push({{r, c}, 0});
                }
                grid[r][c] = -1;
            }
        }

        vi dr = {-1, 0, 1, 0};
        vi dc = {0, -1, 0, 1};

        while (!q.empty()) {
            auto front = q.front();
            int r = front.first.first, c = front.first.second, d = front.second;
            q.pop();
            if (r < 0 || c < 0 || r >= n || c >= n)
                continue;
            if (grid[r][c] != -1)
                continue;
            grid[r][c] = d;
            for (int i = 0; i < 4; i++) {
                q.push({{r + dr[i], c + dc[i]}, d + 1});
            }
        }

        priority_queue<pair<int, ii>> pq;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int r = front.second.first, c = front.second.second, min_d = front.first;
            if (r < 0 || c < 0 || r >= n || c >= n)
                continue;
            if (grid[r][c] == -1)
                continue;
            min_d = min(grid[r][c], min_d);
            grid[r][c] = -1;
            if (r == n - 1 && c == n - 1)
                return min_d;
            for (int i = 0; i < 4; i++) {
                pq.push({min_d, {r + dr[i], c + dc[i]}});
            }
        }
        return 0;
    }
};

int main() {
    vv<int> grid = {{0, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 0, 0, 0}};
    Solution sol;
    cout << sol.maximumSafenessFactor(grid);
}