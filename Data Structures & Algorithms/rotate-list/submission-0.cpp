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
    ListNode* rotateRight(ListNode* head, int k) {
     if (head == nullptr) return nullptr;
        int len = 0;
        ListNode *curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        k %= len;
        if (k == 0) return head;
        curr = head;

        for (int i = 0; i < len - k - 1; i++) {
            curr = curr->next;
        }

        ListNode *newTail = curr;
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        ListNode *newCurr = newHead;
        while (newCurr->next) {
            newCurr = newCurr->next;
        }
        newCurr->next = head;

        return newHead;   
    }
};