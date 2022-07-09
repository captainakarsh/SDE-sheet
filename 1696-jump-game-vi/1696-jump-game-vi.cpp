class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int cur=0;
        priority_queue<pair<int,int>> p;
        p.push({nums[0],0});
        for(int i=1;i<n;++i)
        {
            while(!p.empty() and (p.top().second + k < i))
                p.pop();
            p.push({p.top().first+nums[i],i});
        }
        while(p.top().second != n-1)p.pop();
        return p.top().first;
    }
};