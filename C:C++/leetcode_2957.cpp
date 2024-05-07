#include <iostream>
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
    int removeAlmostEqualCharacters(string word) {
        int ct = 0;
        bool switch_next = false;
        for (int i = 0; i < word.size() - 1; i++) {
            if (switch_next) {
                word[i] = '?';
                switch_next = false;
                ct++;
            }
            if (al_e(word[i], word[i + 1])) {
                switch_next = true;
            }
        }
        return ct + (switch_next ? 1 : 0);
    }

    int al_e(char a, char b) {
        return abs(a - b) <= 1;
    }
};