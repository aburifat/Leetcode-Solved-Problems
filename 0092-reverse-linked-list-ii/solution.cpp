class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(1);
        dummy->next = head;
        
        // Find the node just before the 'left' position
        ListNode* prevLeft  = dummy;
        for (int i = 0; i < left - 1; i++) {
            prevLeft  = prevLeft ->next;
        }
        
        // Initialize the current pointer within the sublist
        ListNode* current = prevLeft ->next;
        
        // Reverse the sublist from 'left' to 'right'
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = prevLeft ->next;
            prevLeft ->next = current->next;
            current->next = current->next->next;
            prevLeft ->next->next = temp;
        }
        
        // Return the modified linked list (skip the dummy node)
        return dummy->next;
    }
};
