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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* end = head;
        int count = 1;

        while (end->next != nullptr) {
            end = end->next;
            count++;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        count = count / 2;
        while (count) {
            end->next = even;
            end = end->next;

            odd->next = even->next;
            odd = odd->next;
            even = odd->next;
            count--;
        }
        end->next=nullptr;
       

        return head;
    }
};