#include <iostream>
#include <set>
#include <map>
#include <numeric>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

// see leetcode_307 for test suite
class NumArray {
public:
    NumArray(vector<int> &nums) : nums(std::move(nums)) {
        chunk_size = int(sqrt(this->nums.size()));
        decomp = vector<int>(ceil(double(this->nums.size()) / chunk_size), -1e8);
    }

    void update(int index, int val) {
        nums[index] = val;
        int chunk = index / chunk_size;
        calc_chunk(chunk);
    }

    int sumRange(int left, int right) {
        right += 1; //exclusive
        int val = 0;
        for (int c = 0; c < decomp.size(); c++) {
            int cstart = c * chunk_size;
            int cend = (c + 1) * chunk_size;
            if (cstart < right and left < cend) {
                //overlap
                if (left <= cstart && right >= cend)
                    val += get_chunk(c);
                else
                    val += calc_range(max(left, cstart), min(right, cend));
            }
        }
        return val;
    }

private:
    vector<int> decomp;
    vector<int> nums;
    int chunk_size;

    int get_chunk(int chunk) {
        if (decomp[chunk] == -1e8)
            calc_chunk(chunk);
        return decomp[chunk];
    }

    void calc_chunk(int chunk) {
        decomp[chunk] = calc_range(chunk * chunk_size, min((chunk + 1) * chunk_size, int(nums.size())));
    }

    int calc_range(int i, int j) {
        return accumulate(nums.begin() + i, nums.begin() + j, 0);
    }
};

int main() {
    vi v{-28, -39, 53, 65, 11, -56, -65, -39, -43, 97};
    NumArray n{v};
    cout << n.sumRange(5, 6) << endl;
    n.update(9, 27);
    cout << n.sumRange(2, 3) << endl;
    cout << "done";
}