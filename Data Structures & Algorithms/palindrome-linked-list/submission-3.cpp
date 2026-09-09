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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* forw = head;
        while (forw->next != nullptr) {
            len++;
            forw = forw->next;
        }
        ++len;
        forw = head;

        int mid = len / 2;
        while (mid--) {
            forw = forw->next;
        }
        if (len % 2 == 1) forw = forw->next;

        ListNode *list2 = forw;
        ListNode *prev = nullptr;
        while (list2) {
            ListNode *next = list2->next;
            list2->next = prev;
            prev = list2;
            list2 = next;
        }
        list2 = prev;

        forw = head;
        while (list2) {
            if (forw->val != list2->val) {
                return false;
            }
            list2 = list2->next;
            forw = forw->next;
        }

        return true;
    }
};