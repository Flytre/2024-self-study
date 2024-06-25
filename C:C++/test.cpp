#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

vi reps;

auto find(int u) -> int {
    return reps[u] = reps[u] == u ? u : find(reps[u]);
}
auto union_set(int u, int v) -> void {
    reps[find(u)] = find(v);
}