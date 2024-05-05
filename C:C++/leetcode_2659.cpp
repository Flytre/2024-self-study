//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>

using namespace std;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int> &nums) {
        vector<int> ascending(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ascending[i] = i;
        sort(ascending.begin(), ascending.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });
        vector<int> seg(nums.size() * 4, 1);
        build(seg, 1, 0, (int) nums.size() - 1);
        long long moves = ascending[0] + 1;
        for(int i = 1; i < ascending.size(); i++) {
            del(seg, 1, 0, (int) nums.size() - 1, ascending[i-1]);
            if(ascending[i-1] < ascending[i]) {
                moves += size(seg, 1, 0, (int) nums.size() - 1, ascending[i-1], ascending[i]);
            } else {
                moves += size(seg, 1, 0, (int) nums.size() - 1, ascending[i-1], (int) nums.size() - 1);
                moves += size(seg, 1, 0, (int) nums.size() - 1, 0, ascending[i]);
            }
        }
        return moves;
    }

    void build(vector<int> &seg, int v, int tl, int tr) {
        if (tr == tl)
            seg[v] = 1;
        else {
            int tm = (tl + tr) / 2;
            build(seg, 2 * v, tl, tm);
            build(seg, 2 * v + 1, tm + 1, tr);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }

    int size(vector<int> &seg, int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return seg[v];
        int tm = (tl + tr) / 2;
        return size(seg, v * 2, tl, tm, l, min(r, tm))
               + size(seg, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void del(vector<int> &seg, int v, int tl, int tr, int idx) {
        if (tl == tr) {
            seg[v] = 0;
        } else {
            int tm = (tl + tr) / 2;
            if (idx <= tm)
                del(seg, v * 2, tl, tm, idx);
            else
                del(seg, v * 2 + 1, tm + 1, tr, idx);
            seg[v] = seg[2 * v] + seg[2 * v + 1];
        }
    }

};

int main() {
    vector<int> nums{1, 2, 4, 3};
    Solution sol;
    cout << sol.countOperationsToEmptyArray(nums);
}