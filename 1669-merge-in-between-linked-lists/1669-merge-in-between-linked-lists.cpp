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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode* beforeA = list1;
        
     
        for (int i = 0; i < a - 1; i++) {
            beforeA = beforeA->next;
        }

        ListNode* atB = list1;
        for (int i = 0; i < b; i++) {
            atB = atB->next;
        }

        
        ListNode* last = list2;
        while (last->next != nullptr) {
            last = last->next;
        }

        
        beforeA->next = list2;
        last->next = atB->next;

        return list1;
    }
};