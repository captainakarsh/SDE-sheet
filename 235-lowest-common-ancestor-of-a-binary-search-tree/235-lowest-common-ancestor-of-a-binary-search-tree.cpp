/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* help(TreeNode* root,TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;
        if(root == p or root == q) return root;
        TreeNode *l=help(root->left,p,q);
        TreeNode *r=help(root->right,p,q);
        if(l and r)
            return root;
        if(!l) return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return help(root,p,q);
    }
};