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

vi audience;
vv<int> strength;

int main() {
    int n, p, k;
    cin >> n >> p >> k;
    audience = vi(n, 0);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        audience[i] = ai;
    }
    auto strength_pq = vector<priority_queue<ii, vector<ii>, greater<>>>(p,
                                                                         priority_queue<ii, vector<ii>, greater<>>()); //min heap
    int val;
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < p; pos++) {
            cin >> val;
            strength_pq[pos].emplace(val - audience[i], i);
            if (strength_pq[pos].size() > p)
                strength_pq[pos].pop();
        }
    }
    cout << "DONE" << endl;

}