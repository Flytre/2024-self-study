#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <float.h>

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
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        vector<pair<double, int>> by_ratio = {};
        by_ratio.reserve(quality.size());
        for (int i = 0; i < quality.size(); i++)
            by_ratio.emplace_back((double) wage[i] / quality[i], quality[i]);
        sort(by_ratio.begin(), by_ratio.end());
        double min_cost = DBL_MAX;

        int running_quality = 0;
        priority_queue<int> max_quality;

        for (int i = 0; i < by_ratio.size(); i++) {
            auto top = by_ratio[i];
            running_quality += top.second;
            max_quality.push(top.second);

            if (max_quality.size() > k) {
                running_quality -= max_quality.top();
                max_quality.pop();
            }

            if (max_quality.size() == k) {
                min_cost = min(min_cost, top.first * running_quality);
            }
        }

        return min_cost;
    }
};

int main() {
    vector<int> quality = {10, 20, 5}, wage = {70, 50, 30};
    Solution sol;
    cout << sol.mincostToHireWorkers(quality, wage, 2);
}