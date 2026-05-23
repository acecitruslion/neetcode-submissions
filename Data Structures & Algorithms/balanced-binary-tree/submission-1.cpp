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

    int height(TreeNode* root, int &maxx) {
        if(root == NULL) return 0;

        int l = height(root->left, maxx);
        int r = height(root->right, maxx);

        if(l == -1 || r == -1) maxx = -1;
        if(abs(l-r) > 1) maxx = -1;

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int maxx = 0;
        height(root, maxx);
        return maxx != -1;
    }
};
