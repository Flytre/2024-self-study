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


ll count(map < ii, map < int, ll >> &mapper) {
    ll sum = 0;
    for (auto &entry: mapper) {
        const ii &key = entry.first;
        map<int, ll> &val = entry.second;

        ll total = 0;
        for (auto &inner: val) {
            total += inner.second;
        }
        for (auto &inner: val) {
            sum += inner.second * (total - inner.second);
        }
    }
    return sum / 2;
}

int main() {
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        vi arr(n, 0);
        int ai;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            arr[i] = ai;
        }
        map<ii, map<int, ll>> mapper;
        ll ct = 0;
        //[same, same, diff]
        for (int i = 0; i < n - 2; i++) {
            mapper[{arr[i], arr[i + 1]}][arr[i + 2]]++;
        }

        ct += count(mapper);
        mapper.clear();

        for (int i = 1; i < n - 1; i++) {
            mapper[{arr[i], arr[i + 1]}][arr[i - 1]]++;
        }
        ct += count(mapper);
        mapper.clear();


        for (int i = 0; i < n - 2; i++) {
            mapper[{arr[i], arr[i + 2]}][arr[i + 1]]++;
        }
        ct += count(mapper);
        cout << ct << endl;
    }
}