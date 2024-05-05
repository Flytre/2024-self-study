//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while(head && head->next) {
            ListNode* c = head;
            ListNode* n = head->next;
            prev->next = n;
            c->next = n->next;
            n->next = c;
            head = c->next;
            prev = c;
        }

        return dummy.next;
    }
};

int main() {
    auto *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    Solution sol;
    sol.swapPairs(head);
}