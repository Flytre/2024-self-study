//
// Created by Aaron Rahman on 4/13/24.
//
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries) {
        vector<bool> flags(2 * n, false);
        int set[2] = {0, 0};
        long long sum = 0;
        int idx = queries.size() - 1;

        while (idx >= 0 && (set[0] < n || set[1] < n)) {
            vector<int> &q = queries[idx--];
            if (!flags[n * q[0] + q[1]]) {
                flags[n * q[0] + q[1]] = true;
                set[q[0]] += 1;
                sum += q[2] * (n - set[q[0] ? 0 : 1]);
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int> > queries = {{0, 0, 1},
                                    {1, 2, 2},
                                    {0, 2, 3},
                                    {1, 0, 4}};
    Solution sol;
    cout << sol.matrixSumQueries(3, queries);
}