//
// Created by Aaron Rahman on 3/21/24.
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
    int longestSubsequence(string s, int k) {
        int l = 0;
        int longest = 0;
        int sum = 0;
        int zeroes = 0;

        for (int r = 0; r < s.size(); r++) {
            sum = (sum << 1) | (s[r] - 48);

            while(!(s[l] - 48)) {
                zeroes++;
                l++;
            }

            while (sum > k) {
                int inv_mask = 1 << (r - l++);
                if (!(sum & inv_mask)) zeroes++;
                sum = sum & ~inv_mask;
            }
            longest = max(longest, r - l + zeroes + 1);
        }

        return longest;
    }
};




int main() {
    Solution sol;
    cout << sol.longestSubsequence("1001010", 5);
}