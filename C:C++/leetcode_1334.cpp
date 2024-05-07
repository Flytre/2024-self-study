//
// Created by Aaron Rahman on 5/6/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        auto fw = vector<vector<int>>(n, vector<int>(n, 10001));
        for (int i = 0; i < n; i++)
            fw[i][i] = 0;

        for (auto &ed: edges)
            fw[ed[0]][ed[1]] = fw[ed[1]][ed[0]] = ed[2];

        for (int node = 0; node < n; node++) {
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    fw[a][b] = min(fw[a][b], fw[a][node] + fw[node][b]);
                }
            }
        }

        auto ans = pair<int, int>{-1, n};
        for (int i = 0; i < n; i++) {
            auto cmp = (int)count_if(fw[i].begin(), fw[i].end(),
                                [&distanceThreshold](const int &v) { return v <= distanceThreshold; });
            if (cmp <= ans.second)
                ans = {i, cmp};
        }

        return ans.first;

    }
};

int main() {
    Solution sol;
    vector<vector<int>> e{{0, 1, 2},
                          {0, 4, 8},
                          {1, 2, 3},
                          {1, 4, 2},
                          {2, 3, 1},
                          {3, 4, 1}};
    cout << sol.findTheCity(5, e, 2);
}