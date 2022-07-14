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
    unordered_map<int,int> m;int index=0;
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int lb,int ub){
       if(ub<lb)
           return NULL;
        TreeNode* tree = new TreeNode(preorder[index]);
       int temp = m[preorder[index++]];
        tree->left = help(preorder,inorder,lb,temp-1);
        tree->right = help(preorder,inorder,temp+1,ub);
        return tree;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m.clear();
        index=0;
        int len = inorder.size();
        for(int i=0;i<len;++i){

            m[inorder[i]] = i;
        }
        return help(preorder,inorder,0,len-1);
    }
};