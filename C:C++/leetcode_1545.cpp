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

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';
        int len = pow(2, n) - 1;
        int mid = len / 2 + 1;
        if (k == mid)
            return '1';
        else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            int offset = len / 2 - (k - mid) + 1;
            return findKthBit(n - 1, offset) == '0' ? '1' : '0';
        }
    }
};

int main() {
    Solution sol;
    cout << sol.findKthBit(30, 423570975) << endl;
}