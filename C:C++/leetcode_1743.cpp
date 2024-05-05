#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {

        map<int, vector<int>> graph;
        for (auto &adjacentPair: adjacentPairs) {
            graph[adjacentPair[0]].push_back(adjacentPair[1]);
            graph[adjacentPair[1]].push_back(adjacentPair[0]);
        }

        auto start = std::find_if(graph.begin(), graph.end(), [](const auto &pair) {
            return pair.second.size() == 1;
        });
        vector<int> ret = {start->first};
        ret.reserve(adjacentPairs.size() + 1);

        while (ret.size() < adjacentPairs.size() + 1) {
            int next = graph[ret.back()][0];
            if (ret.size() > 1 && ret[ret.size() - 2] == next)
                next = graph[ret.back()][1];
            ret.push_back(next);
        }
        return ret;

    }
};


int main() {
    Solution sol;
    vector<vector<int>> adj_pairs = {{2, 1},
                                     {3, 4},
                                     {3, 2}};
    vector<int> arr = sol.restoreArray(adj_pairs);
    cout << 1 << endl;
}