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

    int maxx;

    int height(TreeNode* root) {
        if(!root) return 0;

        int l = height(root->left);
        int r = height(root->right);

        maxx = max(maxx, l+r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxx = 0;
        int t = height(root);
        return maxx;
    }
};
