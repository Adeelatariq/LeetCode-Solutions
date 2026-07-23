class Solution {
public:
    // 1. Place the helper function FIRST
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }

    // 2. Define mergeKLists AFTER the helper
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int k = lists.size();

        while (k > 1) {
            int i = 0, j = k - 1;
            while (i < j) {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++;
                j--;
            }
            k = (k + 1) / 2; // Prevents infinite loop / TLE
        }

        return lists[0];
    }
};
