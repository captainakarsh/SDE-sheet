class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
        int dp[n],maxm=INT_MIN;
        for(int i=n-1;i>=0;--i)
        {
            if(prices[i]>maxm)
            {
                maxm=prices[i];
            }
            dp[i]=maxm;
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans=max(ans,dp[i]-prices[i]);
        }
        return ans;
    }
};