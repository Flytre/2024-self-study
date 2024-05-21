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

vv<int> graph;
vv<ll> dp;
constexpr int mod = 1000000007;

ll dfs(int node, int mask) {
    if (mask >> node & 1)
        return 0;
    mask = mask | (1 << node);
    if (dp[node][mask] != -1)
        return dp[node][mask];
    if (node == graph.size() - 1) return mask == (1 << graph.size()) - 1;
    ll sum = 0;
    for (int child: graph[node]) {
        sum += dfs(child, mask);
    }
    return dp[node][mask] = (sum % mod);
}

int main() {
    int n, m;
    cin >> n >> m;
    graph = vv<int>(n, vi());
    dp = vv<ll>(n, vector<ll>(1 << graph.size(), -1));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    cout << dfs(0, 0) << endl;
}