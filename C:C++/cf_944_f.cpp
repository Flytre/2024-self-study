#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <stdlib.h>
#include <vector>

#define _CRT_SECURE_NO_DEPRECATE


//Wrong Answer!


using namespace std;

static unsigned julery_isqrt(unsigned long val) {
    unsigned long temp, g = 0, b = 0x8000, bshft = 15;
    do {
        if (val >= (temp = (((g << 1) + b) << bshft--))) {
            g += b;
            val -= temp;
        }
    } while (b >>= 1);
    return g;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r;
        cin >> r;
        long long r2 = r * r;
        long long r12 = (r + 1) * (r + 1);
        int axis_ct = 0;
        int quad_ct = 0;
        for (long long x = 0; x < r + 1; x++) {
            long long x2 = x * x;
            long long y2_l = r2 - x2;
            long long y2_u = r12 - x2 - 1;
            long long min_y = julery_isqrt(y2_l);
            long long max_y = julery_isqrt(y2_u);

            if (min_y * min_y < y2_l)
                min_y += 1;
            if (max_y * max_y > y2_u)
                max_y -= 1;

            if (max_y >= min_y) {
                if (x == 0) {
                    axis_ct += (max_y - min_y + 1);
                } else if (min_y == 0) {
                    axis_ct += 1;
                    quad_ct += (max_y - min_y);
                } else {
                    quad_ct += (max_y - min_y + 1);
                }
            }
        }
        cout << quad_ct * 4 + axis_ct * 2 << endl;
    }
}