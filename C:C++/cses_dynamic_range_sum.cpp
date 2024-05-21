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
vi seg_tree;
int n;

void create(vi &arr) {
    seg_tree = vi(2 * n, 0);
    for (int i = n; i < 2 * n; i++)
        seg_tree[i] = arr[i - n];
    for (int i = n - 1; i >= 1; i--)
        seg_tree[i] = min(seg_tree[2 * i], seg_tree[2 * i + 1]);
}

void update(int idx, int val) {
    int i = n + idx;
    seg_tree[i] = val;
    while ((i /= 2) >= 1)
        seg_tree[i] = min(seg_tree[2 * i], seg_tree[2 * i + 1]);
}

int query(int left, int right) {
    //query [left, right)
    int res = 1000000007;
    left += n;
    right += n;
    while (left < right) {
        if (left % 2)
            res = min(res, seg_tree[left++]);
        if (right % 2)
            res = min(res,seg_tree[--right]);

        left /= 2;
        right /= 2;
    }
    return res;
}

int main() {
    int q;
    cin >> n >> q;
    vi arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    create(arr);
    for (int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(a - 1, b);
        } else {
            cout << query(a - 1, b) << endl;
        }
    }
}