class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=INT_MIN,cur=0;
        for(auto i:nums)
        {
            if(i==1) cur++;
            else
            {
                ans=max(ans,cur);
                cur=0;
            }
        }
        ans=max(ans,cur);
        return ans;
    }
};