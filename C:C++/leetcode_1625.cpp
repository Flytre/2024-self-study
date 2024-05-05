//
// Created by Aaron Rahman on 4/6/24.
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
    string findLexSmallestString(string s, int a, int b) {
        vector<string> permutations{1,s};
        for (int start = 0; start <= 1; start++) {
            if (!(start | (b % 2)))
                continue;
            int rot = a;
            int pl = permutations.size();
            while(rot != 0) {
                for(int c = 0; c < pl; c++) {
                    string clone = permutations[c];
                    for (int i = start; i < clone.length(); i += 2) {
                        clone[i] = '0' + (clone[i] - '0' + rot) % 10;
                    }
                    permutations.push_back(clone);
                }
                rot = (rot + a) % 10;
            }
        }

        int shift = 0;
        string ret = string(s.length(), '9');
        do {
            for (int i = 0; i < permutations.size(); i++) {
                permutations[i] = permutations[i].substr(s.length() - b) + permutations[i].substr(0, s.length() - b);
                if (permutations[i] < ret)
                    ret = permutations[i];
            }
            shift = (shift + b) % s.size();
        } while (shift != 0);

        return ret;
    }
};

int main() {
    Solution sol;
    auto s = sol.findLexSmallestString("74", 5, 1);
    cout << s;
}