class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node makes it easy to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        // Continue until both lists and carry are exhausted
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // Add the digit from the first list, if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add the digit from the second list, if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Create a node containing the current digit
            carry = sum / 10;
            current->next = new ListNode(sum % 10);

            // Move to the last node of the result list
            current = current->next;
        }

        // Skip the dummy node and return the result
        return dummy->next;
    }
};