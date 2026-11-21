
class Solution {
public:
    int maxi = 0;

    
    vector<int> solve(TreeNode* root) {
        if (!root)
            return {1, 0, INT_MAX, INT_MIN};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

       
        if (left[0] && right[0] &&
            root->val > left[3] &&
            root->val < right[2]) {

            int sum = left[1] + right[1] + root->val;

            maxi = max(maxi, sum);

            int mini = min(root->val, left[2]);
            int maxiVal = max(root->val, right[3]);

            return {1, sum, mini, maxiVal};
        }

       
        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        maxi = 0;
        solve(root);
        return maxi;
    }
};
