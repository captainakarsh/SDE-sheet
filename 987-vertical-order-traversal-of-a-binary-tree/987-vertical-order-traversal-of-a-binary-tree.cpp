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
void help(TreeNode* root,unordered_map<int,map<int,multiset<int>>>& m,int d,int &mini,int &maxi,int l)
    {
        if(!root) return;
        mini = min(mini,d);
        maxi = max(maxi,d);
        m[d][l].insert(root->val);
        help(root->left,m,d-1,mini,maxi,l+1);
        help(root->right,m,d+1,mini,maxi,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,map<int, multiset<int>>> m;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        help(root,m,0,mini,maxi,0);
        vector<vector<int>> ans;
        for(int i=mini;i<=maxi;++i)
        {
            vector<int> t;
            for(auto j:m[i])
            {
                for(auto k:j.second)
                    t.push_back(k);
            }
            ans.push_back(t);
        }
        return ans;
    }
};