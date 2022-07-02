class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int n1 = hc.size();
        int n2 = vc.size();
        int mhc = hc[0]-0;
        for(int i=1;i<n1;++i)
        {
            mhc = max(mhc,hc[i]-hc[i-1]);
        }
        mhc = max(mhc,h-hc[n1-1]);
        int mvc = vc[0]-0;
        for(int i=1;i<n2;++i)
        {
            mvc = max(mvc,vc[i]-vc[i-1]);
        }
        mvc = max(mvc,w-vc[n2-1]);
        cout<<mhc<<" "<<mvc;
        long long int ans = (long long)mhc*(long long)mvc;
        ans = ans%1000000007;
        return ans;
        
    }
};