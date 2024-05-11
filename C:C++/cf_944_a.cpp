#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a;
        cin >> b;
        cout << min(a, b) << " " << max(a, b) << endl;
    }
}