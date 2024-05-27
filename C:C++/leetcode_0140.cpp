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

template<typename T>
using vvv = vector<vector<vector<T>>>;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set < string > word_bank;
        for (auto &str: wordDict) word_bank.insert(str);
        int n = (int) s.size();
        vector<string> ret{};
        for (int mask = 1 << (n - 1); mask < 1 << n; mask++) {
            int start = 0, valid = 1;
            string modif;
            for (int end = 0; end < n; end++) {
                if ((mask >> end) & 1) {
                    auto sub = s.substr(start, end + 1 - start);
                    valid &= word_bank.find(sub) != word_bank.end();
                    if (!valid) break;
                    modif += sub + " ";
                    start = end + 1;
                }
            }
            if (valid) modif.pop_back(), ret.push_back(modif);
        }
        return ret;
    }
};

int main() {
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution sol;
    sol.wordBreak("catsanddog", wordDict);
}