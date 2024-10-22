#include <iostream>
#include <set>
#include <map>
#include <stack>

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
    int totalStrength(vector<int> &strength) {
        long long MOD = 1'000'000'007;
        const int N = strength.size();


        vector<long long> prefix(N + 1, 0L);
        for (int i = 0; i < N; ++i) {
            prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
        }

        vector<long long> prefix_sum(N + 2, 0L);
        for (int i = 0; i <= N; ++i) {
            prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
        }

        vector<int> left(N, -1);
        vector<int> stack;
        for (int i = 0; i < N; ++i) {
            while (!stack.empty() && strength[stack.back()] >= strength[i]) {
                stack.pop_back();
            }
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }

        vector<int> right(N, N);
        stack.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (!stack.empty() && strength[stack.back()] > strength[i]) {
                stack.pop_back();
            }
            right[i] = stack.empty() ? N : stack.back();
            stack.push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < N; ++i) {
            res += ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD + MOD * 2 -
                    (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD) % MOD * strength[i] % MOD;
            res %= MOD;
        }
        return (int) res;

    }
};

int main() {
    vector<int> data = {1, 3, 1, 2};
    Solution sol;
    cout << sol.totalStrength(data);
}