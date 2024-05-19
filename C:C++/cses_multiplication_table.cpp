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

// 1, 2, 2, 3, 3, 4, 6, 6, 9
ll under(ll n, ll guess) {
    ll sum = 0;
    for (ll per = 1; per <= n; per++)
        sum += min(guess / per, n);
    return sum;
}

int main() {
    ll n;
    cin >> n;

    ll low = 0;
    ll high = n * n;
    ll med_idx = (n * n) / 2 + 1; //one-indexed
    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll less_than_mid = under(n, mid);
        if (less_than_mid >= med_idx) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}