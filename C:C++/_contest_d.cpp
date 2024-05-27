#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

struct NodeData {
    ll l_incl_r_incl;
    ll l_excl_r_incl;
    ll l_excl_r_excl;
    ll l_incl_r_excl;
};

class SegTree {
public:
    SegTree(vector<int> &nums) : seg(nums.size() * 4, {0,0,0,0}), sz(nums.size() - 1) {
        build(nums, 1, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        update(1, 0, sz, index, val);
    }

    ll query(int left, int right) {
        NodeData d = search(1, 0, sz, left, right);
        return max({d.l_excl_r_incl, d.l_excl_r_excl, d.l_incl_r_excl, d.l_incl_r_incl});
    }

    NodeData combine(NodeData v1, NodeData v2) {
        NodeData result = {0,0,0,0};
        result.l_incl_r_incl = handle_update(true, true, v1, v2);
        result.l_incl_r_excl = handle_update(true, false, v1, v2);
        result.l_excl_r_incl = handle_update(false, true, v1, v2);
        result.l_excl_r_excl = handle_update(false, false, v1, v2);
    }

    ll handle_update(bool l_incl, bool r_incl, NodeData v1, NodeData v2) {
        return max({(l_incl ? v1.l_incl_r_excl : v1.l_excl_r_excl) + (r_incl ? v2.l_excl_r_incl : v2.l_excl_r_excl),
                    (l_incl ? v1.l_incl_r_incl : v1.l_excl_r_incl) +  (r_incl ? v2.l_excl_r_incl : v2.l_excl_r_excl),
                    (l_incl ? v1.l_incl_r_excl : v1.l_excl_r_excl) +  (r_incl ? v2.l_incl_r_incl : v2.l_incl_r_excl)}
                   );
    }

private:
    vector<NodeData> seg;
    ll sz;

    void build(vector<int> &nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {max(0, nums[idx]), 0, 0, 0};
            return;
        }
        int m = l + (r - l) / 2;
        build(nums, 2 * idx, l, m);
        build(nums, 2 * idx + 1, m + 1, r);
        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }

    NodeData search(int idx, int l, int r, int target_l, int target_r) {
        if (target_l > target_r)
            return {0, 0, 0, 0};
        if (l == target_l && r == target_r)
            return seg[idx];
        int m = l + (r - l) / 2;
        return combine(search(2 * idx, l, m, target_l, min(m, target_r)),
                       search(2 * idx + 1, m + 1, r, max(m + 1, target_l), target_r));
    }

    void update(int idx, int l, int r, int target_idx, int target_val) {
        if (l == r && r == target_idx) {
            seg[idx] = {max(target_val, 0), 0, 0, 0};
            return;
        }
        int m = l + (r - l) / 2;
        if (target_idx <= m)
            update(2 * idx, l, m, target_idx, target_val);
        else
            update(2 * idx + 1, m + 1, r, target_idx, target_val);
        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        ll ret = 0;
        SegTree seg = SegTree(nums);
        for (auto& query : queries) {
            seg.update(query[0], query[1]);
            ret += seg.query(0,nums.size());
            ret %= 1'000'000'007;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vi nums = {0, -1};
    vv<int> queries = {{0, -5}};
    cout << sol.maximumSumSubsequence(nums, queries);
}