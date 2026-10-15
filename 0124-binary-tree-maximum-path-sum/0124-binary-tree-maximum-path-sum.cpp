/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int solvememo(TreeNode* root,unordered_map<TreeNode*, int> &dp){
         if (root == NULL) return 0;

        if (dp.count(root)) {
            return dp[root];
        }

        int left = max(0, solvememo(root->left, dp));
        int right = max(0, solvememo(root->right, dp));

       
        ans = max(ans, root->val + left + right);

       
        return dp[root] = root->val + max(left, right);






    }
    int maxPathSum(TreeNode* root) {
       unordered_map<TreeNode*, int> dp;
        solvememo(root, dp);
        return ans;
      
    }
};