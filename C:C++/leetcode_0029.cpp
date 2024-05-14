#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" raw types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        uint32_t udividend = dividend == INT_MIN ? static_cast<uint32_t>(INT_MIN) : abs(dividend);
        uint32_t udivisor = divisor == INT_MIN ? static_cast<uint32_t>(INT_MIN) : abs(divisor);
        uint32_t quotient = 0;
        while (udividend >= udivisor) {
            uint32_t value, amt;
            for (value = udivisor, amt = 1;
                 value <= udividend >> 1;
                 value = value << 1, amt = amt << 1);
            quotient += amt;
            udividend -= value;
        }
        if (quotient == 2147483648 && sign == -1) {
            return INT_MIN;
        }
        return sign * (int)(quotient);
    }
};

int main() {
    Solution sol{};
    cout << sol.divide(-2147483648, 1) << endl;
}
