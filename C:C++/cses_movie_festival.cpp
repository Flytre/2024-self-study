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

bool cmp(ii &left, ii &right) {
    if (left.second != right.second)
        return left.second < right.second;
    return left.first < right.first;
}

int main() {
    int n;
    cin >> n;
    vector<ii> movies(n, {0, 0});
    for (int i = 0; i < n; i++) {
        int start, stop;
        cin >> start >> stop;
        movies[i] = {start, stop};
    }
    sort(movies.begin(), movies.end(), cmp);
    int ret = 0;
    int time = 0;
    for (auto & movie : movies) {
        if (movie.first >= time) {
            ret++;
            time = movie.second;
        }
    }
    cout << ret << endl;
}