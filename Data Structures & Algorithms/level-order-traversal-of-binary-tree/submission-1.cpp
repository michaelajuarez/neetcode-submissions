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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> hold;
        hold.push(root);
        vector<vector<int>> retVar;
        
        while (hold.size()) {
            int length = hold.size();
            vector<int> temp;
            for (int i = 0; i < length; i++) {
                TreeNode* current = hold.front();
                hold.pop();
                if (current->left) hold.push(current->left);
                if (current->right) hold.push(current->right);
                temp.push_back(current->val);
            }
            retVar.push_back(temp);
        }
        return retVar;
    }
};
