//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>
#include <stack>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode *head) {
        vector<int> vec{};
        ListNode *iter = head;
        while (iter) {
            vec.push_back(iter->val);
            iter = iter->next;
        }
        int ret = 0;
        for (int i = 0; i < vec.size() / 2; i++)
            ret = max(ret, vec[i] + vec[vec.size() - 1 - i]);
        return ret;
    }
};