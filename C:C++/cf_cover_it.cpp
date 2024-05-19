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

void dfs(
        vector<bool> &values,
        vector<bool> &visited,
        vector<vector<int>> &adjacent,
        int &count,
        int node = 0,
        bool value = false
) {
    if (visited[node]) return;
    values[node] = value;
    visited[node] = true;
    if (value) count++;
    for (auto adjacent_node: adjacent[node]) {
        dfs(values, visited, adjacent, count, adjacent_node, !value);
    }
}

int main() {
    int t;
    cin >> t;
    for (int query = 0; query < t; query++) {
        int n, m;
        cin >> n >> m;
        vv<int> adjacent(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjacent[u - 1].push_back(v - 1);
            adjacent[v - 1].push_back(u - 1);
        }
        vector<bool> values(n);
        vector<bool> visited(n);
        int count = 0;
        bool inv = true;
        dfs(values, visited, adjacent, count);
        if (count > n / 2) {
            count = n - count;
            inv = !inv;
        }
        cout << count << endl;
        for (int i = 0; i < n; i++)
            if (values[i] == inv) cout << i + 1 << " ";
        cout << endl;
    }
}