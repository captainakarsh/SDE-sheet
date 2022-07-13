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
   int findMaxPath(TreeNode* root,int& ans){
        if(!root){
            return 0;
        }
        int fromLeft=max(0,findMaxPath(root->left,ans));
        int fromRight=max(0,findMaxPath(root->right,ans));
		
        ans=max(ans,fromLeft+fromRight+root->val);
        return max(fromLeft,fromRight)+root->val;
        
    }
   int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findMaxPath(root,ans);
        return ans;
    }
 
};