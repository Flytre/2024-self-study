//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>
#include <stack>

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
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        sort(items.begin(), items.end());
        int maxBeauty = 0;
        for (vector<int> &item: items) {
            item[1] = max(maxBeauty, item[1]);
            maxBeauty = item[1];
        }
        for (int &q: queries) {
            q = search(items, q);
        }
        return queries;
    }

    int search(vector<vector<int>> items, int query) {
        int left = -1;
        int right = (int) items.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= query && (mid == items.size() - 1 || items[mid + 1][0] > query)) {
                return items[mid][1];
            } else if (items[mid][0] <= query) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> items = {{1, 2},
                                 {3, 2},
                                 {2, 4},
                                 {5, 6},
                                 {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    Solution sol;
    sol.maximumBeauty(items, queries);
}