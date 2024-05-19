#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;
int n, m;
vv<int> adj;
vv<int> adj_inv;

vector<bool> fv;
int visit_ct = 0;

void dfs(int node, vv<int> &graph) {
    if (fv[node])
        return;
    fv[node] = true;
    visit_ct++;
    for (int neighbor: graph[node])
        dfs(neighbor, graph);
}

int main() {
    cin >> n >> m;

    adj = vv<int>(n, vector<int>());
    adj_inv = vv<int>(n, vector<int>());
    fv = vector<bool>(n, false);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from - 1].push_back(to - 1);
        adj_inv[to - 1].push_back(from - 1);
    }
    dfs(0, adj);

    if (visit_ct < n) {
        cout << "NO" << endl;
        for (int i = 0; i < n; i++) {
            if (!fv[i]) {
                cout << 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }
    visit_ct = 0;
    fv = vector<bool>(n, false);
    dfs(0, adj_inv); //last finished = 0  if there's only 1 scc
    if(visit_ct < n) {
        cout << "NO" << endl;
        for (int i = 0; i < n; i++) {
            if (!fv[i]) {
                cout << i + 1 << " " << 1 << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
}