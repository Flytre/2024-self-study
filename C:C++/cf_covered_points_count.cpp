#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

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

int main() {
    int n;
    cin >> n;
    vector<ll> poi;
    vector<pair<ll, ll>> segments;

    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l, cin >> r;
        poi.push_back(l);
        poi.push_back(r + 1);
        segments.emplace_back(l, r + 1);
    }
    sort(poi.begin(), poi.end());
    poi.erase(unique(poi.begin(), poi.end()), poi.end());
    vi delt(poi.size(), 0);
    for (auto &seg: segments) {
        size_t start = lower_bound(poi.begin(), poi.end(), seg.first) - poi.begin();
        size_t end = lower_bound(poi.begin(), poi.end(), seg.second) - poi.begin();
        delt[start]++;
        delt[end]--;
    }
    vector<ll> width(poi.size() - 1, 0);
    for (int i = 0; i < width.size(); i++) {
        width[i] = poi[i + 1] - poi[i];
    }

    vector<ll> ret(n, 0);
    int tally = 0;
    for (int i = 0; i < width.size(); i++) {
        tally += delt[i];
        if (tally > 0)
            ret[tally - 1] += width[i];
    }
    for (int i = 0; i < n; i++)
        cout << ret[i] << " ";
    cout << endl;
}