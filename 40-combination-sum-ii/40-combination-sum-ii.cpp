class Solution {
public:
        void help(vector<int>& can, int target, vector<vector<int> >& res, vector<int>& r,int i)
    {
        
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        for(int index = i;index<can.size();index++)
        {
            if(can[index]>target) return;
            if(index>i and can[index]==can[index-1] )
                continue;
            r.push_back(can[index]);
            help(can,target - can[index],res,r,index+1);
            r.pop_back();
        }
}
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
              sort(can.begin(),can.end());
        vector<int> t;
        vector<vector<int>> ans;
        help(can,target,ans,t,0);
        return ans;
    }
};