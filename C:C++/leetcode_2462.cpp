//
// Created by Aaron Rahman on 3/29/24.
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
    long long totalCost(vector<int> &costs, int k, int candidates) {
        int left_bound = min(candidates, (int) costs.size() / 2);
        int right_bound = max((int) costs.size() / 2, (int) costs.size() - candidates);

        priority_queue<int, vector<int>, greater<>> left{costs.begin(), costs.begin() + left_bound};
        priority_queue<int, vector<int>, greater<>> right{costs.begin() + right_bound, costs.end()};

        left.push(999999);
        right.push(999999);

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            if (left.top() <= right.top()) {
                sum += left.top();
                left.pop();
                left.push(left_bound < right_bound ? costs[left_bound++] : 999999);
            } else {
                sum += right.top();
                right.pop();
                right.push(right_bound > left_bound ? costs[--right_bound] : 999999);
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> costs{48};
    cout << sol.totalCost(costs, 1, 1);
}