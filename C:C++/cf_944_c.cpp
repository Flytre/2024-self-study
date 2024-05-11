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
    int t, a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        int ct = 0;
        for (int l = a; l != b; l = (l == 12 ? 1 : (l + 1))) {
            if (l == c || l == d) {
                ct += 1;
            }
        }
        if (ct != 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}