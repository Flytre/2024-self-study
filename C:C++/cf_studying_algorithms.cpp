#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


template<typename T>
using vv = vector<vector<T>>;

int main() {
    int N, X;
    cin >> N >> X;
    vi data(N, 0);
    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        data[i] = ai;
    }
    sort(data.begin(), data.end());
    int ct = 0;
    int running = 0;
    for (int i = 0; i < N; i++) {
        if (running + data[i] <= X) {
            ct++;
            running += data[i];
        } else
            break;
    }
    cout << ct << endl;
}