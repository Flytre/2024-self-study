#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>

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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> next_greater = {};
        stack<int> mono_stack = {};

        for (int num : nums2) {
            while (!mono_stack.empty() && mono_stack.top() < num) {
                next_greater[mono_stack.top()] = num;
                mono_stack.pop();
            }
            mono_stack.push(num);
        }

        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            auto f = next_greater.find(nums1[i]);
            ret[i] = f == next_greater.end() ? -1 : f->second;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {6, 3, 4, 5, 7};
    vector<int> nums2 = {6, 3, 4, 5, 7};
    vector<int> ret = sol.nextGreaterElement(nums1, nums2);
    for (int i: ret)
        cout << i << " ";
}