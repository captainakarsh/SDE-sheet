class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        vector<pair<int,int>> v;
        for(auto i:bt)
            v.push_back({i[1],i[0]});
        sort(v.begin(),v.end());
        int ans=0;
        for(int i = v.size()-1;i>=0;--i)
        {
            
            if(v[i].second <= ts)
            {
                ans = ans + (v[i].second * v[i].first);
                ts-=v[i].second;
            }
            else
            {
                ans = ans + (ts * v[i].first);
                break;
            }
            
        }
        return ans;
    }
};