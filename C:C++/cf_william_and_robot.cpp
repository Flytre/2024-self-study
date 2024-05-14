#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

int main() {
    int n;
    cin >> n;
    vi data(n, 0);
    for (int i = 0; i < n; i++) cin >> data[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i += 2) {
        pq.push(data[i]);
        pq.push(data[i + 1]);
        pq.pop();
    }
    ll sum = 0;
    while (!pq.empty())
        sum += pq.top(), pq.pop();
    
    cout << sum << endl;
}
