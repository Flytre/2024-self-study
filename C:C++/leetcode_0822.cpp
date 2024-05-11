#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        vector<int> good(2001, 1);
        unordered_set<int> possibles;
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                good[fronts[i]] = 0;
                possibles.erase(fronts[i]);
            } else {
                if (good[fronts[i]]) possibles.insert(fronts[i]);
                if (good[backs[i]]) possibles.insert(backs[i]);
            }
        }
        return possibles.size() == 0 ? 0 : *min_element(possibles.begin(), possibles.end());

    }
};