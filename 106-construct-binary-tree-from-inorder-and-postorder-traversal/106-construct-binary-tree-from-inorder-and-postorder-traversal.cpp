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
    unordered_map<int,int> m;int index;
    TreeNode* help(vector<int>& postorder, vector<int>& inorder,int lb,int ub){
       if(ub<lb)
           return NULL;
        TreeNode* tree = new TreeNode(postorder[index--]);
       int temp = m[tree->val];
        tree->right = help(postorder,inorder,temp+1,ub);
        tree->left = help(postorder,inorder,lb,temp-1);
        return tree;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m.clear();
        int len = inorder.size();
        index = len-1;
        for(int i=0;i<len;++i){

            m[inorder[i]] = i;
        }
        return help(postorder,inorder,0,len-1);
    }
};