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
    int pre_index = 0;

    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& hold, int left, int right) {
        if (left > right) return nullptr;

        int root_val = preorder[pre_index];
        pre_index ++;
        TreeNode* root = new TreeNode(root_val);
        int mid =  hold[root_val];
        root->left = dfs(preorder, hold, left, mid - 1);
        root->right = dfs(preorder, hold, mid + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hold;
        for (int i = 0; i < inorder.size(); i++) {
            hold[inorder[i]] = i;
        }

        return dfs(preorder, hold, 0, inorder.size()-1);
    }
};
