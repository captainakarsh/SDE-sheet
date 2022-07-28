class Solution {
public:
    bool isAnagram(string s, string t) {
        int dp[26]={0};
        for(auto ch:s)
        {
            dp[ch-'a']++;
        }
        
        for(auto ch:t)
        {
            dp[ch-'a']--;
        }
        for(int i=0;i<26;i++)
            if(dp[i])
                return false;
        return true;
    }
};