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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode *curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;

        int grps = len / k;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroup = &dummy;
        for (int i = 0; i < grps; i++) {
            ListNode *groupStart = curr;
            ListNode *groupEnd = groupStart;
            int cnt = k;
            
            while (cnt-- && curr) {
                curr = curr->next;
            }

            ListNode *nextGroup = curr;
            ListNode *p = groupStart;
            ListNode *prev = nullptr;
            while (p != nextGroup) {
                ListNode *next = p->next;
                p->next = prev;
                prev = p;
                p = next;
            }

            prevGroup->next = prev;
            groupEnd->next = nextGroup;
            prevGroup = groupEnd;
        }

        return dummy.next;
    }
};
