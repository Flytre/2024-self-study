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
    int n, q;
    cin >> n >> q;
    vi arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = arr[i] ^ arr[i - 1];
    }
    for(int qi = 0; qi < q; qi++) {
        int a, b;
        cin >> a >> b;
        cout << (arr[b] ^ arr[a-1]) << endl;
    }
}