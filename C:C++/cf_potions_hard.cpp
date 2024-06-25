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

vector<int> reps; //pre-initialized
auto find(int u) -> int {
    reps[u] = reps[u] == u ? u : find(reps[u]);
}

int main() {
    int n;
    cin >> n;
    vi potions(n, 0);
    for (int i = 0; i < n; i++)
        cin >> potions[i];
    priority_queue<int> pq;
    ll hp = 0;
    for (int potion: potions) {
        hp += potion;
        pq.push(-potion);
        if (hp < 0) hp += pq.top(), pq.pop();
    }
    cout << pq.size();
}