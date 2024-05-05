#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class NumArray {
public:
    NumArray(vector<int> &nums) : seg(nums.size() * 4, 0), sz(nums.size() - 1) {
        build(nums, 1, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        update(1, 0, sz, index, val);
    }

    int sumRange(int left, int right) {
        return search(1, 0, sz, left, right);
    }

private:
    vector<int> seg;
    int sz;

    void build(vector<int> &nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(nums, 2 * idx, l, m);
        build(nums, 2 * idx + 1, m + 1, r);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    int search(int idx, int l, int r, int target_l, int target_r) {
        if (target_l > target_r)
            return 0;
        if (l == target_l && r == target_r)
            return seg[idx];
        int m = l + (r - l) / 2;
        return search(2 * idx, l, m, target_l, min(m, target_r))
               + search(2 * idx + 1, m + 1, r, max(m + 1, target_l), target_r);
    }

    void update(int idx, int l, int r, int target_idx, int target_val) {
        if (l == r && r == target_idx) {
            seg[idx] = target_val;
            return;
        }
        int m = l + (r - l) / 2;
        if (target_idx <= m)
            update(2 * idx, l, m, target_idx, target_val);
        else
            update(2 * idx + 1, m + 1, r, target_idx, target_val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums{-9, 8};
    NumArray *obj = new NumArray(nums);
    obj->update(0, 3);
    cout << obj->sumRange(1, 1) << endl;
    cout << obj->sumRange(0, 1) << endl;
    obj->update(1, -3);
    cout << obj->sumRange(0, 1) << endl;
}