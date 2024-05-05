//
// Created by Aaron Rahman on 3/21/24.
//

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
    bool isRobotBounded(string instructions) {
        pair<int, int> coords{0, 0};
        int dir = 0;
        for (int i = 0; i < instructions.size(); i++) {
            switch (instructions[i]) {
                case 'G':
                    coords.second += 1;
                    break;
                case 'L':
                    dir = (dir - 1) % 4;
                    swap(coords.first, coords.second);
                    coords.first *= -1;
                    break;
                case 'R':
                    dir = (dir + 1) % 4;
                    swap(coords.first, coords.second);
                    coords.second *= -1;
                    break;
            }
        }
        return dir != 0 || (coords.first == 0 && coords.second == 0);
    }
};
