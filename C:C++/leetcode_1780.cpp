#include <iostream>
#include <set>
#include <map>

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
    bool checkPowersOfThree(int n) {
        int c = 1;
        while (n > 0) {
            if (n == c)
                return true;
            else if (n % (3 * c))
                n -= c;
            c *= 3;
        }
        return false;
    }
};

int main() {
    Solution sol;
    sol.checkPowersOfThree(12);
}