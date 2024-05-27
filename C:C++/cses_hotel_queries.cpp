#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <cmath>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;
vi seg_tree;
int n;

//pair format: <max value, max index>
int combine(int left, int right) {
    return max(left, right);
}

void create(vi &free_rooms) {
    seg_tree = vi(2 * n, 0);
    for (int i = n; i < 2 * n; i++)
        seg_tree[i] = free_rooms[i - n];
    for (int i = n - 1; i >= 1; i--) {
        seg_tree[i] = combine(seg_tree[2 * i], seg_tree[2 * i + 1]);
    }
}

void update(int idx, int delta) {
    int i = n - 1 + idx;
    seg_tree[i] += delta;
    while ((i /= 2) >= 1)
        seg_tree[i] = combine(seg_tree[2 * i], seg_tree[2 * i + 1]);
}

int query(int target) {
    int idx = 1;
    if (seg_tree[idx] < target)
        return 0;
    while (idx < n) {
        if (seg_tree[2 * idx] >= target)
            idx *= 2;
        else
            idx = 2 * idx + 1;
    }
    return idx - n + 1;
}

int lowest_above() {
    if (n == 0) return 1;
    return 1 << (int) (std::ceil(std::log2(n)));
}

int main() {
    int m;
    cin >> n >> m;
    int old_n = n;
    n = lowest_above();
    vi free_rooms(n, 0);
    for (int i = 0; i < old_n; i++)
        cin >> free_rooms[i];
    create(free_rooms);
    for (int i = 0; i < m; i++) {
        int required_room;
        cin >> required_room;
        auto index = query(required_room);
        cout << index << " ";
        if (index != 0)
            update(index, -required_room);
    }
}