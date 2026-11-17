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
    int max_depth = 0;

    void dfs(TreeNode* cur, int depth) {
        if (!cur) {
            return;
        }

        depth++;
        dfs(cur->left, depth);
        dfs(cur->right, depth);
        max_depth = max(max_depth, depth);
    }

    int maxDepth(TreeNode* root) {
        int cur_depth = 0;
        dfs(root, cur_depth);
        return max_depth;
    }
};
