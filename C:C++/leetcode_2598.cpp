//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>
#include <queue>

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
    int findSmallestInteger(vector<int> &nums, int value) {
        vector<int> buckets(value, 0);
        for (int num: nums)
            buckets[((num % value) + value) % value] += 1;
        int trial = 0;
        while (buckets[trial++ % value]-- > 0);
        return trial - 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1,-10,7,13,6,8};
    cout << sol.findSmallestInteger(nums, 7);
}