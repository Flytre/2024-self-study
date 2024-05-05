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
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, z = 0; i < nums.size(); i++)
            if(nums[i])
                swap(nums[i], nums[i-z]);
            else z++;
    }
};

int main() {
    auto v = vi{0,1,0,3,12};
    auto sol = Solution();
    sol.moveZeroes(v);
    for(int val : v) {
        std::cout << val << " ";
    }
}