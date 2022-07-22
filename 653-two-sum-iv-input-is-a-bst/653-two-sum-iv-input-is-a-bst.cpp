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
    void help(TreeNode *root,unordered_set<int> &s)
    {
        if(root)
        {
            s.insert(root->val);
            help(root->left,s);
            help(root->right,s);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        help(root,s);
        for(auto i:s)
        {
           // cout<<i<<" ";
            if(k-i != i)
            {
                if(s.find(k-i)!=s.end())
                    return true;
            }
                
        }
        return false;
    }
};