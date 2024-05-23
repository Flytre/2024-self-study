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

int n;
vector<ll> tickets(n, 0);
ll x, a, y, b, k;
ll lcm_val;

ll gcd(ll first, ll second) {
    if (first == 0)
        return second;
    return gcd(second % first, first);
}

ll lcm(ll first, ll second) {
    return first * second / gcd(first, second);
}

bool has_required_contribution(int ticket_count) {
    if (ticket_count == n + 1) return true;
    int both = ticket_count / lcm_val;
    int type_a = ticket_count / a - both;
    int type_b = ticket_count / b - both;
    return k <= (tickets[both]) * (x + y) / 100
                + (tickets[type_a + both] - tickets[both]) * x / 100
                + (tickets[type_b + type_a + both] - tickets[type_a + both]) * y / 100;
}

int main() {
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        cin >> n;
        tickets = vector<ll>(n + 1, 2'000'000'000);
        for (int pi = 0; pi < n; pi++) cin >> tickets[pi];

        sort(tickets.begin(), tickets.end(), greater<>());

        //one-indexed prefix sum, since tickets[0] = 0 is a dummy value
        tickets[0] = 0;
        for (int pi = 1; pi <= n; pi++) tickets[pi] += tickets[pi - 1];

        cin >> x >> a >> y >> b >> k;
        if (y > x) {
            swap(x, y);
            swap(a, b);
        }
        lcm_val = lcm(a, b);
        int l = 1, r = n + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (has_required_contribution(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << ((l == n + 1) ? -1 : l) << endl;
    }
}