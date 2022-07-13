class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t="";
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ')
            {
                if(t.length())v.push_back(t);
                t="";
                continue;
            }
            t=t+s[i];
        }
        if(t.length())v.push_back(t);
        reverse(v.begin(),v.end());
        string ans="";
        for(auto i:v)
        {
            if(!ans.length())
            ans=ans+i;
            else
                ans=ans + " "+i;
        }
        return ans;
    }
};