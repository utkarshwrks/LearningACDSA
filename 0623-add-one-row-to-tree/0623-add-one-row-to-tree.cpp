class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        dfs(root, val, 1, depth);
        return root;
    }

    void dfs(TreeNode* cur, int val, int level, int depth) {
        if (cur == nullptr) return;

        if (level == depth - 1) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            leftNode->left = cur->left;
            rightNode->right = cur->right;

            cur->left = leftNode;
            cur->right = rightNode;

            return;
        }

        dfs(cur->left, val, level + 1, depth);
        dfs(cur->right, val, level + 1, depth);
    }
};