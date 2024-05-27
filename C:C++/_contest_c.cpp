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

class Solution {
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        ll ct = 0;
        unordered_map<int, int> freq;
        for (auto num: nums2)
            freq[num]++;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % k == 0) {
                int value = nums1[i] / k;
                //find all nums2 such that val = v * nums2, for any v;
                int sqrt_num = std::sqrt(value);
                for (int factor = 1; factor <= sqrt_num; ++factor) {
                    if (value % factor == 0) {
                        ct += freq[factor];
                        if (factor != value / factor) {
                            ct += freq[value / factor];
                        }
                    }
                }
            }
        }
        return ct;
    }
};

int main() {
    Solution sol;
    vi nums1 = {1,2,4, 12};
    vi nums2 = {2, 4};
    cout << sol.numberOfPairs(nums1, nums2, 3);
}