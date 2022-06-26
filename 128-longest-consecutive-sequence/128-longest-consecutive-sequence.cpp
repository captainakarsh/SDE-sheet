class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> m;
        for(auto i:nums)
            m[i]=1;
        int ans=INT_MIN;
        for(auto i:nums)
        {
            if(m[i-1]) continue;
            int next=i+1,c=1;
            while(m[next])
            {
                c++;
                next++;;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};