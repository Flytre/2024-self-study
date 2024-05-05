//
// Created by Aaron Rahman on 3/27/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        pair<int, int> modeEven = modeCount(nums, [](auto i) { return i % 2 == 0; });
        pair<int, int> modeOdd = modeCount(nums, [](auto i) { return i % 2 == 1; });
        if (modeEven.first == modeOdd.first) {
            pair<int, int> evenAlt = modeCount(nums,
                                               [&nums, &modeEven](auto i) {
                                                   return nums[i] != modeEven.first && i % 2 == 0;
                                               });
            pair<int, int> oddAlt = modeCount(nums,
                                              [&nums, &modeEven](auto i) {
                                                  return nums[i] != modeEven.first && i % 2 == 1;
                                              });
            return static_cast<int>(nums.size()) -
                   max(evenAlt.second + modeOdd.second, oddAlt.second + modeEven.second);

        } else
            return static_cast<int>(nums.size()) - modeEven.second - modeOdd.second;
    }

private:
    pair<int, int> modeCount(vector<int> &nums, const function<bool(int)> &predicate) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (predicate(i)) {
                freq[nums[i]]++;
            }
        }

        if(freq.empty()) {
            return {0, 0};
        }

        auto max_val = max_element(freq.begin(), freq.end(), [](auto a, auto b) {
            return a.second < b.second;
        });
        return *max_val;
    }
};

int main() {
    vector<int> nums{1, 2, 2, 2, 2};
    Solution sol;
    cout << sol.minimumOperations(nums);
}