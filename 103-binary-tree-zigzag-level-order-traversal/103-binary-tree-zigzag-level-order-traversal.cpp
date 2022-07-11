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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root == NULL) return v;
        stack<TreeNode*> st,st1;
        bool foo = 0;
        st.push(root);
        
        while(!st.empty() or !st1.empty()){
            vector<int> ace;
            
            if(!foo){
         
                auto it = st.top();
                while(!st.empty()){
                    it = st.top();st.pop();
                    ace.push_back(it -> val);
                    if(it -> left != NULL)
                      st1.push(it -> left);
                    if(it -> right != NULL)
                       st1.push(it -> right);
                }
            }
            
            // else we need to move left to right in next iteration
            
            else{
                auto it = st1.top();
                while(!st1.empty()){
                    it = st1.top();st1.pop();
                    ace.push_back(it -> val);
                    if(it -> right != NULL)
                      st.push(it -> right);
                    if(it -> left != NULL)
                      st.push(it -> left);
                }  
            }
            
            foo ^= 1;
            v.push_back(ace);
            
        }
        return v;
    }
};