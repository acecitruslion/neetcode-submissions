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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        int large = max(p->val, q->val);
        int small = min(p->val, q->val);

        while(root) {
            if(root->val > large) {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if(root->val < small) {
                return lowestCommonAncestor(root->right, p, q);
            }
            else {
                return root;
            }
        }
        
    }
};
