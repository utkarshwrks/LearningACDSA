class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            if (level == depth - 1) {
                while (sz--) {
                    TreeNode* cur = q.front();
                    q.pop();

                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);

                    leftNode->left = cur->left;
                    rightNode->right = cur->right;

                    cur->left = leftNode;
                    cur->right = rightNode;
                }

                break;
            }

            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            level++;
        }

        return root;
    }
};