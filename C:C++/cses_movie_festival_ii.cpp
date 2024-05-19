#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

bool cmp(ii &left, ii &right) {
    if (left.second != right.second)
        return left.second < right.second;
    return left.first < right.first;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ii> movies;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        movies.emplace_back(l, r);
    }
    sort(movies.begin(), movies.end(), cmp);

    queue<int> busy;
    multiset<int> available;
    for (int i = 0; i < k; i++)
        available.insert(0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (!busy.empty() && busy.front() <= movies[i].first) {
            available.insert(busy.front());
            busy.pop();
        auto it = available.upper_bound(movies[i].first);
        if (busy.size() < k && it != available.begin()) {
            available.erase(prev(it));
            count++;
            busy.push(movies[i].second);
        }
    }
    cout << count << endl;
}