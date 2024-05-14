#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


template<typename T>
using vv = vector<vector<T>>;

bool destroy_recur(multiset<int> &a, int x, int init_x, vv<int> &chain) {
    if (a.empty()) {
        cout << "YES" << endl;
        cout << init_x << endl;
        for (auto &val: chain)
            cout << val[0] << " " << val[1] << endl;
        return true;
    }
    int maxi = *a.rbegin();
    int opp = x - maxi;
    a.erase(a.find(maxi));
    if (a.find(opp) == a.end()) {
        return false;
    }
    chain.push_back({opp, maxi});
    a.erase(a.find(opp));
    if (!destroy_recur(a, maxi, init_x, chain)) {
        return false;
    }
    return true;
}

void destroy(multiset<int> &a) {
    for (auto iter = a.begin(); iter != prev(a.end()); iter = next(iter)) {
        vv<int> chain;
        auto clone = a;
        if (destroy_recur(clone, *iter + *a.rbegin(), *iter + *a.rbegin(), chain))
            return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        multiset<int> a;
        int ai;
        for (int d = 0; d < 2 * n; d++) cin >> ai, a.insert(ai);
        destroy(a);
    }
}