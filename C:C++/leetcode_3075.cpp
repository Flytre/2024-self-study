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
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        long long sum = 0;
        sort(happiness.begin(), happiness.end(), [](int a, int b) { return a > b; });
        for (int i = 0; i < k; i++)
            sum += max(0, happiness[i] - i);
        return sum;
    }
};