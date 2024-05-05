#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;


class Node {
public:
    int value;
    Node *left;
    Node *right;
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        tree = construct_tree(nums, 0, nums.size()-1);
        size = nums.size();
    }

    void update(int index, int val) {
        update(index, val, 0, size-1, tree);
    }

    int sumRange(int left, int right) {
        return sumRange(left, right, 0, size-1, tree);
    }

private:
    Node *tree;
    int size;

    int sumRange(int left, int right, int L, int R, Node* ptr) {
        if(left == L && right == R)
            return ptr->value;
        int sum = 0;
        int m = L + (R - L) / 2;
        if(left <= m) {
            sum += sumRange(left, min(m, right), L, m, ptr->left);
        }
        if(m < right) {
            sum += sumRange(max(left, m+1), right, m+1, R, ptr->right);
        }
        return sum;
    }

    void update(int index, int val, int L, int R, Node* ptr) {
        int m = L + (R - L) / 2;

        if(L == R) {
            ptr->value = val;
            return;
        }

        if(index <= m) update(index, val, L, m, ptr->left);
        else update(index, val, m+1, R, ptr->right);
        ptr->value = ptr->left->value + ptr->right->value;

    }

    Node *construct_tree(vector<int> &nums, int L, int R) {
        if (nums.empty())
            return nullptr;

        if (L == R) {
            Node *base = new Node{};
            base->value = nums[L];
            return base;
        }
        int m = L + (R - L) / 2;
        Node *me = new Node{0, construct_tree(nums, L, m), construct_tree(nums, m + 1, R)};
        me->value = me->left->value + me->right->value;
        return me;
    }
};

int main() {
    vi v{10, 13, -5, 3, 4, -1, -3, 7, 4};
    NumArray n{v};
    cout << n.sumRange(0,8) << endl;
    n.update(2, 15);
    cout << n.sumRange(0, 8) << endl;
    int x = 0;
}
