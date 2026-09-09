/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        ListNode *prev = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;

        ListNode *left = fast;
        ListNode *right = slow;

        while (left && right) {
            ListNode *nextLeft = left->next;
            ListNode *nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }
    }
};
