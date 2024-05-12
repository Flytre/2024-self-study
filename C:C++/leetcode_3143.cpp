#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>

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
    int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
        vector<pair<int, char>> p_map{};
        vector<bool> contained(26, false);
        for (int i = 0; i < points.size(); i++) {
            p_map.push_back({max(abs(points[i][0]), abs(points[i][1])), s[i]});
        }
        sort(p_map.begin(), p_map.end());
        int ret = 0;
        for (int i = 0; i < p_map.size();) {
            int square_size = p_map[i].first;
            int to_add = 0;
            while(i < p_map.size() && p_map[i].first == square_size) {
                if (contained[p_map[i].second - 'a'])
                    return ret;
                to_add += 1;
                contained[p_map[i].second - 'a'] = true;
                i++;
            }
            ret += to_add;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> pts = {{1, 1}, {-1, -1}, {2, -2}};
    string s = "ccd";
    cout << sol.maxPointsInsideSquare(pts, s);
}