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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       // Dummy node handles reversal starting at position 1
        ListNode dummy(0);
        dummy.next = head;

        // Move prev to the node just before position left
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node to be reversed
        ListNode* curr = prev->next;

        // Move each next node to the front of the section
        for (int i = 0; i < right - left; i++) {
            ListNode* next = curr->next;

            // Remove next from its current position
            curr->next = next->next;

            // Insert next immediately after prev
            next->next = prev->next;
            prev->next = next;
        }

        // Return the updated head
        return dummy.next; 
    }
};