class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxi) {
        if (root == NULL) return 0;

        int count = 0;

        if (root->val >= maxi) {
            count = 1;
        }

        maxi = max(maxi, root->val);

        count += dfs(root->left, maxi);
        count += dfs(root->right, maxi);

        return count;
    }
};