#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>
#include <random>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class Solution {
public:

    int known_min;

    vector<int> findPermutation(vector<int> &nums) {
        known_min = INT_MAX;
        vector<int> curr = {};
        vector<int> dp(pow(2, nums.size()), 10000);
        return mp(nums, curr, 0, 0, 0).second;
    }

    bool isLessThanElementwise(const std::vector<int> &v1, const std::vector<int> &v2) {
        if (v1.size() != v2.size()) {
            std::cerr << "Vectors are of different sizes." << std::endl;
            return false;
        }

        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] >= v2[i]) {
                return false;
            }
        }

        return true;
    }

    pair<int, vector<int>> mp(vector<int> &nums, vector<int> &curr, int used, int score, int depth) {

        if (score > known_min)
            return {999999, {}};

        if (depth == nums.size()) {
            known_min = min(score, known_min);
            return {score, curr};
        }
        pair<int, vector<int>> min_pair = {10000, {}};
        vector<int> nums2 = nums;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(nums2.begin(), nums2.end(), g);
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            i = nums2[i];
            if (!(used & (1 << i))) {
                int sdelt = curr.size() > 0 ? abs(curr[curr.size() - 1] - nums[i]) : 0;
                curr.push_back(i);
                used |= (1 << i);
                auto returned = mp(nums, curr, used, score + sdelt, depth + 1);
                if (returned.first < min_pair.first ||
                    (returned.first == min_pair.first && isLessThanElementwise(returned.second, min_pair.second))) {
                    min_pair = std::move(returned);
                }
                used &= ~(1 << i);
                curr.pop_back();
            }
            i = j;
        }
        return min_pair;
    }
};

int main() {
    Solution sol;
    vi data = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto r = sol.findPermutation(data);
    for (int i: r)
        cout << i << " ";
}