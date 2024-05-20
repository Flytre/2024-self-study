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

int main() {
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        string raw;
        cin >> raw;
        map<char, int> ctr;
        for (int i = 0; i < n; i++) {
            ctr[raw[i]]++;
        }
        int ns = ctr['N'] - ctr['S'];
        int ew = ctr['E'] - ctr['W'];
        if (ns == 0 && ew == 0 && n < 4) {
            cout << "NO" << endl;
            continue;
        }

        if (ns % 2 || ew % 2) {
            cout << "NO" << endl;
            continue;
        }
        int dest_ns = ns / 2;
        int dest_ew = ew / 2;
        int heli_ns = 0, heli_ew = 0;
        string instr(n, 'x');
        for (int i = 0; i < n; i++) {
            if (raw[i] == 'N') instr[i] = heli_ns < dest_ns ? (heli_ns++, 'H') : 'R';
            if (raw[i] == 'S') instr[i] = heli_ns > dest_ns ? (heli_ns--, 'H') : 'R';
            if (raw[i] == 'E') instr[i] = heli_ew < dest_ew ? (heli_ew++, 'H') : 'R';
            if (raw[i] == 'W') instr[i] = heli_ew > dest_ew ? (heli_ew--, 'H') : 'R';
        }
        if (heli_ns == 0 && heli_ew == 0) {
            if (ctr['N'] > 0) {
                instr[raw.find('N')] = 'H';
                instr[raw.find('S')] = 'H';
            } else {
                instr[raw.find('E')] = 'H';
                instr[raw.find('W')] = 'H';
            }
        }
        cout << instr << endl;
    }
}