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
    int maximumScore(vector<int> &nums, int k) {
        int l = k, r = k;
        int ret = nums[k];
        int c_min = nums[k];
        while (0 < l && r < nums.size() - 1) {
            if (nums[l - 1] > nums[r + 1])
                c_min = min(nums[--l], c_min);
            else
                c_min = min(nums[++r], c_min);
            ret = max(ret, c_min * (r - l + 1));
        }
        while(0 < l) {
            c_min = min(nums[--l], c_min);
            ret = max(ret, c_min * (r - l + 1));
        }
        while(r < nums.size() - 1) {
            c_min = min(nums[++r], c_min);
            ret = max(ret, c_min * (r - l + 1));
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,4,3,7,4,5};
    cout << sol.maximumScore(nums,3);
}