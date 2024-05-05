//
// Created by Aaron Rahman on 3/28/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        Node* ret = root;
        Node* placebo = new Node(0, nullptr, nullptr, nullptr);
        Node* before = placebo;

        while(root) {
            Node* level_start = before;
            while(root) {
                if(root->left) {
                    before->next = root->left;
                    before = before->next;
                }
                if(root->right) {
                    before->next = root->right;
                    before = before->next;
                }
                root = root->next;
            }
            root = level_start->next;
            placebo->next = nullptr;
            before = placebo;
        }

        delete placebo;
        return ret;
    }

//    Node *connect(Node *root) {
//
//        if(!root)
//            return root;
//
//        queue<Node *> q({root});
//        int level_ctr = 1;
//        while (!q.empty()) {
//            int next_level_ctr = 0;
//            for (int i = 0; i < level_ctr; i++) {
//                Node *node = q.front();
//                q.pop();
//                if (i + 1 < level_ctr)
//                    node->next = q.front();
//
//                if (node->left) {
//                    q.push(node->left);
//                    next_level_ctr++;
//                }
//                if (node->right) {
//                    q.push(node->right);
//                    next_level_ctr++;
//                }
//            }
//            level_ctr = next_level_ctr;
//
//        }
//        return root;
//    }
};

int main() {
    Solution sol;
    Node* tree = new Node{1, new Node{2, new Node{4}, new Node{5}, nullptr}, new Node{3, nullptr, new Node{7}, nullptr}, nullptr};
    sol.connect(tree);
}