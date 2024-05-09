#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>

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
    long long countSubstrings(string s, char c) {
        int n = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                ++n;
            }
        }
        return static_cast<long long>(n)*(n+1)/2;
    }
};