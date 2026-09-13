class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        while (head) {
            if (st.count(head->val) &&
                (head->next == nullptr || !st.count(head->next->val))) {
                ans++;
            }

            head = head->next;
        }

        return ans;
    }
};