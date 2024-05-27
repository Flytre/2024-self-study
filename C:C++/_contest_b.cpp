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
    string compressedString(string word) {
        int ptr = 1;
        string comp;
        char curr = word[0];
        int ctr = 1;
        while (ptr < word.size()) {
            if (word[ptr] == curr && ctr < 9) {
                ctr++;
            } else {
                comp += to_string(ctr);
                comp += curr;
                curr = word[ptr];
                ctr = 1;
            }
            ptr++;
        }
        comp += to_string(ctr);
        comp += curr;
        return comp;
    }
};

int main() {
    Solution sol;
    cout << sol.compressedString("aaaaaaaaaaaaaabb");
}