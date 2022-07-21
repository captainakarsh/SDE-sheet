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
    TreeNode* help(vector<int>& pre,int i,int j)
    {
        if(i>j) return NULL;
        TreeNode *t = new TreeNode(pre[i]);
        int k=i+1;
        while(k<=j and pre[k]<pre[i])k++;
        t->left = help(pre,i+1,k-1);
        t->right = help(pre,k,j);
        return t;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return help(pre,0,pre.size()-1);
    }
};