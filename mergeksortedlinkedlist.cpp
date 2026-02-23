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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            minheap;

        int k = lists.size();
        if (k == 0)
            return NULL;

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minheap.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!minheap.empty()) {
            ListNode* top = minheap.top().second;
            minheap.pop();

            if (top->next != NULL) {
                minheap.push({top->next->val, top->next});
            }

            if (head == NULL) {
                head = tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};