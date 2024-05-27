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
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        int max_score = 0;
        vi letter_ct(26, 0);
        vi word_score(words.size(), 0);
        for (char letter: letters) letter_ct[letter - 'a']++;

        for (int i = 0; i < words.size(); i++)
            for (char ch: words[i])
                word_score[i] += score[ch - 'a'];

        //worst case complexity: 2^14 * 14 * 15 = 3.5M * O(1)
        for (int mask = 1; mask < 1 << words.size(); mask++) {
            vi counter = letter_ct;
            bool valid = true;
            int cscore = 0;
            for (int shift = 0; shift < words.size(); shift++) {
                if ((mask >> shift) & 1) {
                    for (char offset: words[shift]) {
                        counter[offset - 'a']--;
                        valid &= counter[offset - 'a'] >= 0;
                    }
                    cscore += word_score[shift];
                }
                if (!valid) break;
            }
            if (valid) max_score = max(max_score, cscore);
        }
        return max_score;
    }
};

int main() {
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vi score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Solution sol;
    cout << sol.maxScoreWords(words, letters, score);
}