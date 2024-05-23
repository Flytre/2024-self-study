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

vi tree;
vv<int> graph;
vector<ll> sums;
vi vals;

ll dfs(int node, int parent) {
    for (int child: graph[node])
        if (child != parent)
            sums[node] += dfs(child, tree[child] = node);
    return sums[node];
}

//TLE: should log n log n with seg tree but im too lazy
int main() {
    int n, q;
    cin >> n >> q;
    tree = vi(n, -1);
    sums = vector<ll>(n, 0);
    vals = vi(n, 0);
    graph = vv<int>(n, vi());

    for (int i = 0; i < n; i++)
        cin >> sums[i], vals[i] = (int) sums[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);

    int t, s, x;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> s >> x;
            ll delta = x - vals[--s];
            vals[s] = x;
            while (s != -1) {
                sums[s] += delta;
                s = tree[s];
            }
        } else {
            cin >> s;
            cout << sums[s - 1] << endl;
        }
    }
}