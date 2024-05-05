//
// Created by Aaron Rahman on 4/1/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <queue>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> mod(60, 0);
        int ct = 0;
        for (int i = 0; i < time.size(); i++) {
            ct += mod[(60 - (time[i] % 60)) % 60];
            mod[time[i] % 60] += 1;
        }
        return ct;
    }
};

int main() {
    Solution sol;
    vector<int> time{30, 20, 150, 100, 40, 20};
    cout << sol.numPairsDivisibleBy60(time);
}