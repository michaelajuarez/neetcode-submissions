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
    int smallest = 0;
    int retVal = -1;

    void dfs(TreeNode* root, int target) {
        if (!root) return;
        dfs(root->left, target);
        smallest++;
        if (smallest == target) {
            retVal = root->val;
        }
        dfs(root->right, target);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return retVal;
    }
};
