class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* ans = head;
        int sum = 0;

        while (curr) {
            if (curr->val != 0) {
                sum += curr->val;
            } else {
                ans->val = sum;
                sum = 0;

                if (curr->next)
                    ans = ans->next;

            }
            curr = curr->next;
        }

        ans->next = nullptr;

        return head;
    }
};