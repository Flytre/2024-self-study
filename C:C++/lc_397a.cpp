#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>

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
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> hash;
        for (int i = 0; i < t.size(); i++)
            hash[t[i]] = i;
        int diff = 0;
        for(int i = 0; i < s.size(); i++) {
            diff += abs(i - hash[s[i]]);
        }
        return diff;
    }
};

int main() {

}