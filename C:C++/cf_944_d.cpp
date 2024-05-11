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
    int t;
    string curr;
    cin >> t;
    getline(cin, curr);
    for (int i = 0; i < t; i++) {
        getline(cin, curr);
        int ch_count = 1;
        bool zero_one = false;
        char ch = curr[0];
        int cuts = 0;
        for (int j = 1; j < curr.size(); j++) {
            if (curr[j] != ch) {
                if (ch == '0' && curr[j] == '1')
                    zero_one = true;
                ch_count += 1;
                cuts += 1;
                ch = curr[j];
            }
        }
        // 0-1 section: -1, n cuts = n+1 pieces = +1
        cout << (ch_count == 1 ? 1 : (cuts + 1 + (zero_one ? -1 : 0))) << endl;
    }
}