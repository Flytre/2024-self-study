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

ListNode* vectorToList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head; // Return the head of the list
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-101, head);
        ListNode *prev = &dummy;
        while (head) {
            ListNode *n = head->next;
            bool del = n && n->val == head->val;
            while(n && n->val == head->val) {
                head->next = n->next;
                n = head->next;
            }
            if(del) {
                prev->next = head->next;
            } else
                prev = prev->next;
            head = n;
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    vector<int> entry{1,1,2,2,5,5,5};
    sol.deleteDuplicates(vectorToList(entry));
}