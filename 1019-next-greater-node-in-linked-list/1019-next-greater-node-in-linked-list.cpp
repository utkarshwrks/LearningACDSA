class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<ListNode*, int>> st;

        ListNode* curr = head;
        int i = 0;

        while (curr) {
            ans.push_back(0);

            while (!st.empty() && st.top().first->val < curr->val) {
                ans[st.top().second] = curr->val;
                st.pop();
            }

            st.push({curr, i});
            curr = curr->next;
            i++;
        }

        return ans;
    }
};