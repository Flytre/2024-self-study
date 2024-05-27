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

int main() {
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        vi permutation(n, 0);
        int middle = 0, geq = 1, less = 0; //midpoint, numbers > / <=
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
            if (permutation[i] == n / 2 + 1) middle = i;
        }
        for (int i = middle - 1; i >= 0; i--)
            if (permutation[i] == n / 2 - less)
                less++;
        for (int i = middle + 1; i < n; i++)
            if (permutation[i] == n / 2 + 1 + geq)
                geq++;
        cout << max(n / 2 + (n % 2) - geq, n / 2 - less) << endl;
    }
}
