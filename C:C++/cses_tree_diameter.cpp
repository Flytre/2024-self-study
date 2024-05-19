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

int max_diameter = 0;
vv<int> graph;
vector<bool> visited;

int height_of(int node) {
    if (visited[node])
        return -1;
    visited[node] = true;
    vi heights = {0};
    for (int child: graph[node])
        heights.push_back(height_of(child) + 1);

    //O(n) find 2 greatest elements
    partial_sort(heights.begin(), heights.begin() + 2, heights.end(), std::greater<int>());
    max_diameter = max(max_diameter, heights[0] + heights[1]);
    return heights[0];
}

int main() {
    int n;
    cin >> n;
    graph = vv<int>(n, vi());
    visited = vector<bool>(n, 0);

    int a, b;
    for (int edge = 0; edge < n - 1; edge++) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    height_of(0); //arbitrary
    cout << max_diameter << endl;
}