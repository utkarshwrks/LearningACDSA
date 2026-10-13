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
    int dfs(unordered_map<int, list<int>>& mp,
            int src, set<int>& visited) {

        visited.insert(src);
        int time = 0;

        for (int neigh : mp[src]) {
            if (!visited.contains(neigh)) {
                time = max(time, 1 + dfs(mp, neigh, visited));
            }
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,list<int>> mp;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
             TreeNode* node = q.front();
            q.pop();

            if(node->left){
                mp[node->val].push_back(node->left->val);
                mp[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right){
                mp[node->val].push_back(node->right->val);
                mp[node->right->val].push_back(node->val);
                q.push(node->right);
            }
            
        }
        set<int> s;
        return dfs(mp,start,s);
        
    }
};