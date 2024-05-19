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

vv<int> graph;
ll ct[2] = {0, 0};

void dfs(int node, int parent, int depth) {
    ct[depth % 2]++;
    for (int v: graph[node])
        if (v != parent)
            dfs(v, node, depth + 1);
}

int main() {
    int n;
    cin >> n;
    graph = vv<int>(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[v - 1].push_back(u - 1);
        graph[u - 1].push_back(v - 1);
    }

    dfs(0, -1, 0);

    cout << (ct[0] * ct[1]) - (n - 1) << endl;
}
