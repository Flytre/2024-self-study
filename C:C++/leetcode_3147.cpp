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
    int maximumEnergy(vector<int> &energy, int k) {
        int m = INT_MIN;
        for (int i = energy.size() - 1; i > energy.size() - 1 - k; i--) {
            int j = i;
            int curr = 0;
            while (j >= 0) {
                curr += energy[j];
                m = max(m, curr);
                j -= k;
            }
        }
        return m;
    }
};

int main() {
    Solution sol;
    vector<int> en{-2, -3, -1};
    cout << sol.maximumEnergy(en, 2);
}