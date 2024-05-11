#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

int main() {
    int n;
    cin >> n;
    string curr;
    getline(cin, curr);
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> map;
        getline(cin, curr);
        for (int j = 0; j < curr.size(); j++) {
            map.insert_or_assign(curr[j], j);
        }
        if (map.size() == 1)
            cout << "NO" << endl;
        else {
            auto iter = map.begin();
            auto iter2 = next(iter);
            auto val1 = iter->second;
            auto val2 = iter2->second;
            swap(curr[val1], curr[val2]);
            cout << "YES" << endl;
            cout << curr << endl;
        }
    }
}