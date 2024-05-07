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
    static constexpr int mod = 1000000007;

    int maxSum(vector<int> &nums, int k) {
        array<int, 32> bit_count = {};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 31; j++) {
                if ((nums[i] >> j) & 1)
                    bit_count[j]++;
            }
        }

        vector<long long> v(k, 0);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 31; j++) {
                if (bit_count[j] > 0) {
                    bit_count[j]--;
                    v[i] |= (1 << j);
                }
            }
        }
        long long s = 0;
        for (int i = 0; i < k; i++) {
            long long ni = nums[i];
            s += (ni * ni) % mod;
            s = s % mod;
        }
        return (int) s;
    }
};