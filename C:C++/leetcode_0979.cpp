#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int distributeCoins(TreeNode *root) {
        moves = 0;
        recur(root);
        return moves;
    }

    int recur(TreeNode *root) { //format <excess coins, moves incl. into this node>
        if (root->left == nullptr && root->right == nullptr)
            return root->val - 1;

        if (root->left != nullptr) {
            int left = recur(root->left);
            moves += abs(left);
            root->val += left;
        }

        if (root->right != nullptr) {
            int right = recur(root->right);
            moves += abs(right);
            root->val += right;
        }
        return root->val - 1;
    }

private:
    int moves = 0;
};

int main() {
    auto *tree = new TreeNode(4, new TreeNode(0, nullptr, new TreeNode(0, nullptr, new TreeNode(0))), nullptr);
    Solution sol;
    cout << sol.distributeCoins(tree);
}