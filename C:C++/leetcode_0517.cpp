//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &v) {
        int sum = 0, n = v.size();
        for (auto &i: v)sum += i;
        if (sum % n)return -1;
        int target = sum / n;
        int throughput = 0;
        int ans = 0;
        for (auto &i: v) {
            throughput += i - target;
            ans = max({(i - target), ans, abs(throughput)});
        }
        return ans;
    }
};

//always give from most and give to min
int main() {
    Solution sol;
    vector<int> test{10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0};
    cout << sol.findMinMoves(test) << endl;
}