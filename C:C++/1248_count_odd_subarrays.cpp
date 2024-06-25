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

template<typename T>
using vvv = vector<vector<vector<T>>>;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int leading_start = 0;
        int trailing_start = -1;
        int odd_ct = 0;
        int ans = 0;
        for(int end = 0; end < nums.size(); end++) {
            odd_ct += nums[end] % 2 == 1;
            if(odd_ct > k)
                trailing_start = leading_start;
            while(odd_ct > k) {
                leading_start++;
                odd_ct -= nums[leading_start] % 2 == 1;
            }
            if(odd_ct == k) {
                ans += leading_start - trailing_start;
            }
        }

        return ans;
    }
};

int main() {
    vi in = {};
}