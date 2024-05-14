#include <iostream>
#include <vector>
#include <set>
#include <map>

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
    int n, q;
    cin >> n >> q;
    char ch;
    vv<bool> forest(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch;
            if (ch == '*')
                forest[i][j] = true;
        }
    }
    vv<int> prefix(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = forest[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    int r1, c1, r2, c2;
    for (int m = 0; m < q; m++) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefix[r2][c2] + prefix[r1 - 1][c1 - 1] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] << endl;
    }
}