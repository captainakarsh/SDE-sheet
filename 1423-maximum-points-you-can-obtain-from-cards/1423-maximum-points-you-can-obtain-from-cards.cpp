class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        int s=0;
        for(int i=0;i<n;++i)
            s+=cp[i];
        //cout<<s<<" ";
        int cur=0;
        int m=INT_MAX;
        for(int i=0;i<n-k;++i)
        cur+=cp[i];
        for(int i=n-k;i<n;++i)
        {
            m=min(m,cur);
            cur-=cp[i-(n-k)];
            cur+=cp[i];
        }
        m=min(m,cur);
        //cout<<m<<" ";
        if(m==INT_MAX)
            return s;
        return s-m;
    }
};