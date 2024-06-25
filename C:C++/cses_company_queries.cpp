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
#include <cmath>

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
    int h = (int) ceil(log2(n)) + 1;
    vector<vector<int>> bosses(n + 1, vector<int>(h, -1));
    for (int i = 2; i <= n; i++)
        cin >> bosses[i][0];
    for (int j = 1; j < h; j++)
        for (int i = 1; i <= n; i++)
            bosses[i][j] = bosses[i][j - 1] == -1 ? -1 : bosses[bosses[i][j - 1]][j - 1];
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        while(k > 0 && x != -1) {
            int next = floor(log2(k));
            x = bosses[x][next];
            k -= (int)pow(2, next);
        }
        cout << x << endl;
    }
}