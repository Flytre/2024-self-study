#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

int loc(vi& poi, int val) {
    return lower_bound(poi.begin(), poi.end(), val) - poi.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vi poi = {};
    vv<int> updates;
    vv<int> queries;
    for (int i = 0; i < N; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        poi.push_back(l);
        poi.push_back(r);
        updates.push_back({l, r, v});
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        poi.push_back(l);
        poi.push_back(r);
        queries.push_back({l, r});
    }
    sort(poi.begin(), poi.end());
    poi.erase(unique(poi.begin(), poi.end()), poi.end());

    vll delta(poi.size(), 0);
    vll width(poi.size() - 1, 0);
    for (auto &update: updates) {
        delta[loc(poi, update[0])] += update[2];
        delta[loc(poi, update[1])] -= update[2];
    }
    for (int i = 0; i < poi.size() - 1; i++)
        width[i] = poi[i + 1] - poi[i];

    vll sum(poi.size(), 0);
    sum[0] = 0;
    ll curr_level = 0;
    for (int i = 1; i < poi.size(); i++) {
        curr_level += delta[i - 1];
        sum[i] = sum[i - 1] + curr_level * width[i - 1];
    }
    for (auto &query: queries) {
        cout << sum[loc(poi, query[1])] - sum[loc(poi, query[0])] << endl;
    }
}