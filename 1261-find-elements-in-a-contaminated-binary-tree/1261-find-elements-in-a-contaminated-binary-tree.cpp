class FindElements {
public:
    unordered_set<int> st;

    void recover(TreeNode* root, int val) {
        if (root == nullptr) return;

        root->val = val;
        st.insert(val);

        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }

    FindElements(TreeNode* root) {
        recover(root, 0);
    }

    bool find(int target) {
        return st.count(target) > 0;
    }
};