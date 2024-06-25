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
    int countTriplets(vector<int> &arr) {
        int count = 0;
        int n = arr.size();
        vi prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] ^ arr[i - 1];

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j; k < n; k++) {
                    int a = prefix[j] ^ prefix[i];
                    int b = prefix[k + 1] ^ prefix[j];
                    count += a == b;
                }
        return count;
    }
};