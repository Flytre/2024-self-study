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

double obj(double h, double c, double t, double n) {
    return (h * (n + 1) + c * (n)) / (2 * n + 1.0) - t;
}

int main() {
    int T;
    cin >> T;
    for (int Ti = 0; Ti < T; Ti++) {
        int h, c, t;
        cin >> h >> c >> t;
        if (h + c >= 2 * t) {
            cout << 2 << endl;
            continue;
        }
        //last non-negative;
        int l = 0, r = 10'000'000;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (obj(h, c, t, m) >= 0) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        //compare last non-negative, first negative
        if (abs(obj(h, c, t, l)) <= abs(obj(h, c, t, l + 1)))
            cout << 2 * l + 1 << endl;
        else
            cout << 2 * l + 3 << endl;
    }
}