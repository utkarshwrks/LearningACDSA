/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        root->right = insert(root->right, val);
        return root;
    }
    
    TreeNode* helper(TreeNode* root, TreeNode*& real) {
        if (root == NULL) return real;

        helper(root->left, real);
        real = insert(real, root->val);
        helper(root->right, real);

        return real;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* real=NULL;
        return helper(root,real);
        
    }
};