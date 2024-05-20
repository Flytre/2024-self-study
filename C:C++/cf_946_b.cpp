#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <unordered_map>
using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;
        vector<bool> found(26, false);
        for (char ch: s) found[ch - 'a'] = true;

        string encoding;
        for (char j = 0; j < 26; j++)
            if (found[j]) encoding += (char) (j + 'a');

        unordered_map<char, char> decoder;
        for (int j = 0; j < encoding.size(); j++) decoder[encoding[j]] = encoding[encoding.size() - 1 - j];

        for (char &j: s) j = decoder[j];

        cout << s << endl;
    }
}