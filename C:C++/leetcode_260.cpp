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
    vector<int> singleNumber(vector<int> &nums) {
        map<int, int> ctr;
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
            total ^= nums[i];
        for (int i = 0; i < nums.size(); i++)
            ctr[total ^ nums[i]]++;
        vi res(2, 0);
        int ptr = 0;
        for (auto iter = ctr.begin(); iter != ctr.end(); iter++)
            if (iter->second == 1) res[ptr++] = iter->first;
        return res;
    }
};