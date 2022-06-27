class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)return 0;
        unordered_map<int,int> m;
        int ans=INT_MIN;
        int i=1,j=0;
        m[s[0]]=1;
        while(i<s.length())
        {
            m[s[i]]++;
            while(m[s[i]]>1)
            {
                ans=max(ans,i-j);
                m[s[j]]--;
                j++;
            }
            i++;
        }
        return ans=max(ans,i-j);
    }
};