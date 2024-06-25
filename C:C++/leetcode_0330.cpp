#include <iostream>
#include <set>
#include <map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //add all powers of two under n
        //live update ur personal n each time
        //[1,2,3,4,5]: n =1 -> n = 3 -> n = 6 -> n = 10 -> n = 15
        //this works because in all cases, a[i+1] ≤ n + 1 so new max
        //is equal to n + a[i+1]
        //basically our invariant is in ALL cases n by index i should   equal max sum of a1...ai
        long long curr_n = 1;
        int patches = 0;
        if(nums[0] != 1)
            patches++, nums.insert(nums.begin(), 1);
        int i = 1;
        while(curr_n < n && i < nums.size()) {
            while(nums[i] > curr_n + 1 && curr_n < n) {
                patches++;
                curr_n = 2*curr_n + 1;
            }
            if(curr_n < n) {
                curr_n = curr_n + nums[i];
            }
            i++;
        }
        while(curr_n < n) {
            patches++;
            curr_n = 2*curr_n + 1;
        }
        return patches;
    }
};

int main() {
    vi arr = {1,2,31,33};
    int n = 2147483647;
    Solution sol;
    sol.minPatches(arr, n);
}