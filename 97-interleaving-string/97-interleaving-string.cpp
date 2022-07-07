class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
           int s1Len=s1.length(),s2Len=s2.length(),s3Len=s3.length(),i,j;
        if((s1Len+s2Len) != s3Len)
            return false;
        bool dp[s1Len+1][s2Len+1];
        dp[0][0]=true;
        for(i=1;i<=s2Len;++i)
         if(s3[i-1] == s2[i-1])
             dp[0][i]=dp[0][i-1];
        else
            dp[0][i]=false;
        
         for(i=1;i<=s1Len;++i)
         if(s3[i-1] == s1[i-1])
             dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=false;
        
        for(i=1;i<=s1Len;++i){
            for(j=1;j<=s2Len;++j){
                dp[i][j]=false;
                if(s3[i+j-1] == s2[j-1])
                    dp[i][j]=dp[i][j-1];
                if(s3[i+j-1] == s1[i-1])
                    dp[i][j]=dp[i][j]==true?true:dp[i-1][j];
              
            }
        }
        return dp[s1Len][s2Len];

    }
};