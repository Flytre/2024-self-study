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

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y; //x = 1x1, y = 2x2
        cin >> x >> y;
        int doubles = y / 2;
        int screens = doubles;
        x -= doubles * 7;
        if (y % 2) {
            screens += 1;
            x -= 11;
        }
        screens += x > 0 ? x / 15 + (x % 15 ? 1 : 0) : 0;
        cout << screens << endl;
    }
}