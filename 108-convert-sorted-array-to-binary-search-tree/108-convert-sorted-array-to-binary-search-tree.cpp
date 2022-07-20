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
    TreeNode* help(vector<int>& nums,int i,int j)
    {
        if(i>j) return NULL;
        int m = (i+j)>>1;
        TreeNode *t = new TreeNode(nums[m]);
        t->left = help(nums,i,m-1);
        t->right = help(nums,m+1,j);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
};