class Solution {
public:
    void reorderList(ListNode* head) {
        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Step 3: Merge two halves
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            l1->next = l2;
            l2->next = next1;
            l1 = next1;
            l2 = next2;
        }
    }
};
