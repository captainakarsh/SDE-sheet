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
    bool help(TreeNode *l,TreeNode *r)
    {
        if(!l and !r) return true;
        if(!l or !r) return false;
        if(l->val != r->val) return false;
        bool j = help(l->left,r->right);
        bool k = help(l->right,r->left);
        if(j and k) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return help(root,root);
    }
};