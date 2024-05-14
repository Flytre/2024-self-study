#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
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

set<int> flips;
multiset<int> ret;
string binaryString;

void modify(int x) {
    if (x == 0 || x == binaryString.size()) return;
    auto iter = flips.find(x);
    if (iter != flips.end()) {
        int a = *prev(iter), b = *next(iter);
        ret.erase(ret.find(b - x));
        ret.erase(ret.find(x - a));
        ret.insert(b - a);
        flips.erase(iter);
    } else {
        iter = flips.insert(x).first;
        int a = *prev(iter), b = *next(iter);
        ret.erase(ret.find(b - a));
        ret.insert(x - a), ret.insert(b - x);
    }
}

int main() {
    cin >> binaryString;
    flips.insert(0);
    for (int i = 1; i < binaryString.size(); i++) {
        if (binaryString[i] != binaryString[i - 1])
            flips.insert(i);
    }
    flips.insert((int) binaryString.size());
    auto iter = flips.begin();
    auto prev_iter = *iter;
    for (iter++; iter != flips.end(); iter++) {
        ret.insert(*iter - prev_iter);
        prev_iter = *iter;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        modify(x - 1);
        modify(x);
        cout << *ret.rbegin() << " ";
    }
}