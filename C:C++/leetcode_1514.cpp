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
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
        vector<double> max_prob(n, 0);
        max_prob[start_node] = 1;
        priority_queue<int, vector<int>, function<bool(int, int)>> pq(
                [&](int i, int j) { return max_prob[i] < max_prob[j]; }
        );

        vector<vector<pair<int, double>>> adj_lists(n, vector<pair<int, double>>());
        for (int i = 0; i < edges.size(); i++) {
            adj_lists[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj_lists[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        pq.push(start_node);
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            for (auto &neighbor: adj_lists[curr]) {
                if (max_prob[neighbor.first] < max_prob[curr] * neighbor.second) {
                    max_prob[neighbor.first] = max_prob[curr] * neighbor.second;
                    pq.push(neighbor.first);
                }
            }
        }
        return max_prob[end_node];
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0;
    int end = 2;

    Solution sol;
    cout << "Maximum probability from node " << start << " to node " << end << " is: ";
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}