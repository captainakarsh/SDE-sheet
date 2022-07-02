class Solution {
    bool isP(string S)
{
 
    string P = S;
    reverse(P.begin(), P.end());

    if (S == P) {
        return true;
    }
    // Otherwise
    else {
return false;
    }
}
public:
    void help(string &s,int index,vector<string> &t,vector<vector<string>>& ans)
    {
        if(index == s.length())
        {
            ans.push_back(t);
            return;
        }
        for(int i=index;i<s.length();++i)
        {
            string temp = s.substr(index,(i-index)+1);
            if(!isP(temp))continue;
            t.push_back(temp);
            help(s,i+1,t,ans);
            t.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        help(s,0,t,ans);
        return ans;
    }
};