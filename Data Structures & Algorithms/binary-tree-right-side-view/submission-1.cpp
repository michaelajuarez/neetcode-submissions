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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> hold;
        vector<int> retArr;
        hold.push(root);

        while (hold.size()) {
            int size = hold.size();
            bool level_done = false;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = hold.front();
                hold.pop();

                if (cur->right) {
                    hold.push(cur->right);
                }
                if (cur->left) {
                    hold.push(cur->left);
                }

                if (!level_done) {
                    retArr.push_back(cur->val);
                    level_done = true;
                }
            }
        }
        return retArr;
    }
};
