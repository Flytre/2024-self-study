#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int start = 0;
        int max_length = 0;
        for (int end = 1; end <= s.size(); end++) {
            cost += abs(t[end - 1] - s[end - 1]);
            while (start < end && cost > maxCost) {
                cost -= abs(t[start] - s[start]);
                start++;
            }
            max_length = max(max_length, end - start);
        }
        return max_length;
    }
};