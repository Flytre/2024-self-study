#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        //precompute palindromic substrings in O(n^2)
        vv<bool> palindromes(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) palindromes[i][i] = true;
        for (int i = 0; i < s.size() - 1; i++) palindromes[i][i + 1] = s[i] == s[i + 1];
        for (int length = 3; length <= s.size(); length++)
            for (int i = 0; i <= s.size() - length; i++)
                palindromes[i][i + length - 1] = s[i] == s[i + length - 1] && palindromes[i + 1][i + length - 2];

        //bitmasking in n * 2^n
        vector<vector<string>> ret = {};
        for (int mask = 1 << (s.size() - 1); mask < 1 << s.size(); mask++) {
            int start = 0;
            int end = 0;
            bool valid = true;
            string curr;
            vector<string> cvec;
            while (end < s.size()) {
                curr += s[end];
                if ((mask >> end) & 1) {
                    if (!palindromes[start][end]) {
                        valid = false;
                        break;
                    }
                    cvec.emplace_back(curr);
                    curr = "";
                    start = end + 1;
                }
                end++;
            }
            if (valid) ret.push_back(cvec);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    auto blah = sol.partition("ababbaba");
    cout << "DONE" << endl;
}