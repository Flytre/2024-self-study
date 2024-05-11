#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct FractionComparator {
    std::vector<int> &arr;

    FractionComparator(std::vector<int> &array) : arr(array) {}

    bool operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
        return arr[p1.first] * arr[p2.second] > arr[p1.second] * arr[p2.first];
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, FractionComparator> pq((FractionComparator(arr)));
        for (int i = 0; i < arr.size(); i++) {
            pq.push({i, arr.size() - 1});
        }
        for (int i = 0; i < k-1; i++) {
            if (pq.top().second > 0)
                pq.emplace(pq.top().first, pq.top().second - 1);
            pq.pop();
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};

int main() {
    Solution sol;
    vector<int> data = {1, 2, 3, 5};
    int k = 3;
    vector<int> res = sol.kthSmallestPrimeFraction(data, k);
    cout << res[0] << " " << res[1] << endl;
}