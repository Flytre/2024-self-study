//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1ptr = 0, v2ptr = 0;
        while (v1ptr < version1.length() && v2ptr < version2.length()) {
            int v1next = version1.find('.', v1ptr);
            int v2next = version2.find('.', v2ptr);
            if (v1next == -1) v1next = version1.length();
            if (v2next == -1) v2next = version2.length();
            int c = cmp(version1, version2, v1ptr, v1next, v2ptr, v2next);
            if (c != 0) return c;
            v1ptr = v1next + 1;
            v2ptr = v2next + 1;
        }
        while (v1ptr < version1.length())
            if (version1[v1ptr++] != '0' && version1[v1ptr - 1] != '.')
                return 1;
        while (v2ptr < version2.length())
            if (version2[v2ptr++] != '0' && version2[v2ptr - 1] != '.')
                return -1;
        return 0;
    }

    int cmp(string &r1, string &r2, int r1s, int r1e, int r2s, int r2e) {
        int r1i = r1s, r2i = r2s;
        while (r1[r1i] == '0' && r1i < r1e - 1)
            r1i += 1;
        while (r2[r2i] == '0' && r2i < r2e - 1)
            r2i += 1;
        if (r1e - r1i != r2e - r2i)
            return r1e - r1i < r2e - r2i ? -1 : 1;
        for (; r1i < r1e; r1i++, r2i++) {
            if (r1[r1i] != r2[r2i])
                return r1[r1i] < r2[r2i] ? -1 : 1;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string s1 = "1.0";
    string s2 = "1.0.0";
    cout << sol.compareVersion(s1, s2);
}