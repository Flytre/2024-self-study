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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        //Using bellman ford, but we relax k times instead of n
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for (int epoch = 0; epoch < k+1; epoch++) {
            vector<int> temp(dist);
            for (auto &cost: flights) {
                temp[cost[1]] = min(dist[cost[0]] + cost[2], temp[cost[1]]);
            }
            dist = temp;
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, K = 1;

    Solution sol;
    int result = sol.findCheapestPrice(n, flights, src, dst, K);
    cout << "The cheapest price is: " << result << endl;

    return 0;
}