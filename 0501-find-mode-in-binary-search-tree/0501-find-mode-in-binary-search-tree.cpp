
class Solution {
public:
    vector<int> ans;
    int prev = 0;
    int currFreq = 0;
    int maxFreq = 0;
    bool first = true;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (first || root->val != prev) {
            currFreq = 1;
            first = false;
        } else {
            currFreq++;
        }

        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (currFreq == maxFreq) {
            ans.push_back(root->val);
        }

        prev = root->val;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
