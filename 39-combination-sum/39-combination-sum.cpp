class Solution {
public:
 
    void help(vector<int>& can, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        
        while(i <  can.size() && target - can[i] >= 0)
        {
            r.push_back(can[i]);
    
            help(can,target - can[i],res,r,i);
            ++i;
            r.pop_back();
        }
}
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int> t;
        vector<vector<int>> ans;
        help(can,target,ans,t,0);
        return ans;
    }
};