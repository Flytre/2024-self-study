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

vi input;
int n, k;

bool can_raise(int to) {
    int start = input[n / 2];
    if (start >= to)
        return true;
    ll s = 0;
    for (int i = n / 2; i < n; i++) {
        s += max(0, to - input[i]);
    }
    return s <= k;
}

int bin_last(int low, int high) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (can_raise(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        input.push_back(d);
    }
    sort(input.begin(), input.end());
    cout << bin_last(1, *input.rbegin() + k) << endl;
    //O(nlog(max(a_i)+k) + nlogn) = worse case = 10^5 log(2 10^9) = 3.2 * 10^6
    return 0;
}