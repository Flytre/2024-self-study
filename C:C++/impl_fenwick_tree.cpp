//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class FenwickTree {

    vector<int> bit;
    int n;

public:

    FenwickTree(vector<int> &arr) {
        n = arr.size() + 1;
        bit = vector<int>(n + 1, 0);
        for (size_t i = 0; i < arr.size(); i++)
            add(i, arr[i]);
    }

    int sum(int i) {
        int ret = 0;
        for (++i; i > 0; i -= i & -i)
            ret += bit[i];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int add(int i, int delta) {
        for (++i; i < n; i += i & -i)
            bit[i] += delta;
    }

};

int main() {
    vector<int> data = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    auto f = FenwickTree(data);
    printf("%d\n", f.sum(5));
    cout << "DONE" << endl;
}