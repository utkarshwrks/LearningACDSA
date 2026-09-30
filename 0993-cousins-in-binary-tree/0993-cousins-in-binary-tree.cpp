class Solution {
public:
    pair<int, int> solve(TreeNode* root, int sib, int parent, int depth) {
        if (root == NULL) {
            return {-1, -1};
        }

        if (root->val == sib) {
            return {depth, parent};
        }

        pair<int, int> left = solve(root->left, sib, root->val, depth + 1);

        if (left.first != -1) {
            return left;
        }

        pair<int, int> right = solve(root->right, sib, root->val, depth + 1);

        return right;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> gotx = solve(root, x, root->val, 0);
        pair<int, int> goty = solve(root, y, root->val, 0);

        if (gotx.first == goty.first && gotx.second != goty.second) {
            return true;
        }

        return false;
    }
};