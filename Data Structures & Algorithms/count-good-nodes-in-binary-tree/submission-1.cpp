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
    int good_nodes = 0;

    void dfs(TreeNode* cur, int max_val) {
        if (!cur) return;
        if (cur->val >= max_val) {
            good_nodes++;
            max_val = max(max_val, cur->val);
        }
        dfs(cur->left, max_val);
        dfs(cur->right, max_val);
        return;
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return good_nodes;
    }
};
