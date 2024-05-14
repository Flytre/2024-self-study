#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


int main() {
    int n;
    cin >> n;
    vi data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vector<ll> prefix(n, 0);
    prefix[0] = data[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + data[i];
    ll c_res = prefix[0];
    ll c_min = 0;
    for (int i = 0; i < n; i++) {
        c_res = max(c_res, prefix[i] - c_min);
        c_min = min(c_min, prefix[i]);
    }
    cout << c_res;
}