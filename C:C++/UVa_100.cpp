#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist);

int calc_path_length(map<int, int>&, int);

int main() {
    map<int, int> cycle_lengths;
    cycle_lengths[1] = 1;

    int x, y;
    while(cin >> x && cin >> y) {
        int start = min(x, y), end = max(x, y);
        int max = 0;
        for(int i = start; i <= end; ++i)
            max = std::max(max, calc_path_length(cycle_lengths, i));
        cout << x << " " << y << " " << max << endl;
    }
    return 0;
}

int calc_path_length(map<int, int>& cycle_lengths, int i) {
    auto found = cycle_lengths.find(i);
    if(found != cycle_lengths.end())
        return found->second;
    int next_i = i % 2 == 0 ? (i / 2) : (3*i + 1);
    int val = 1 + calc_path_length(cycle_lengths, next_i);
    cycle_lengths[i] = val;
    return val;
}

