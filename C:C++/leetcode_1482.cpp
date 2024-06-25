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
    int can_bloom(vector<int>& bloomDay, int m, int k, int guess) {
        int bouquet_ct = 0;
        int current_ct = 0;
        for(auto bd : bloomDay) {
            if(bd <= guess)
                current_ct++;
            else {
                bouquet_ct += current_ct / k;
                current_ct = 0;
            }
        }
        bouquet_ct += current_ct / k;
        return bouquet_ct >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int max_bloom_day = 0;
        for(int bd : bloomDay)
            max_bloom_day = max(max_bloom_day, bd);
        int left = 0, right = max_bloom_day + 1;
        //we want to find first true:
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(can_bloom(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (left == max_bloom_day + 1) ? -1 : left;
    }
};

int main() {
    Solution sol;
    vi bd = {1, 10, 3, 10, 2};
    cout << sol.minDays(bd, 3, 1);
}