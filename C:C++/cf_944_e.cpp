#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <stdlib.h>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

int do_query(vector<pair<int, int>> &v, int pt) {
    auto last = v[v.size() - 1];
    if (pt == last.first)
        return last.second;

    //no bin search
    int idx = 0;
    while (v[idx + 1].first <= pt) {
        idx += 1;
    }

    if (v[idx].first == pt)
        return v[idx].second;

    double speed = ((double) (v[idx + 1].second - v[idx].second) / (v[idx + 1].first - v[idx].first));
    return v[idx].second + (pt - v[idx].first) * speed;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<pair<int, int>> v(k + 1, {0, 0});
        for (int j = 0; j < k; j++) {
            int a_j;
            cin >> a_j;
            v[j + 1].first = a_j;
        }
        for (int j = 0; j < k; j++) {
            int b_j;
            cin >> b_j;
            v[j + 1].second = b_j;
        }
        for (int j = 0; j < q; j++) {
            int query;
            cin >> query;
            cout << do_query(v, query) << " ";
        }
        cout << endl;
    }
}