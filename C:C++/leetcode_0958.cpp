//
// Created by Aaron Rahman on 3/23/24.
//

#include "leetcode_0958.h"
#include <queue>
#include <algorithm>

using namespace std;

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
    bool isCompleteTree(TreeNode *root) {
        deque<TreeNode *> q;
        q.push_back(root);
        bool nulled = false;
        while (!q.empty()) {
            TreeNode *val = q.front();
            q.pop_front();

            if (val) {
                if (nulled) return false;
                q.push_back(val->left);
                q.push_back(val->right);
            } else {
                nulled = true;
            }

        }
        return true;
    }
};

int main() {

}