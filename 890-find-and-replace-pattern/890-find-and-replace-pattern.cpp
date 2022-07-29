class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string patt) {
        int n = patt.length();
        bool dp[n];
        dp[0] = true;
        unordered_map<char,int> m;
        for(int i=0;i<n;++i) m[patt[i]]++;
        for(int i=1;i<n;++i)
            dp[i] = patt[i]!=patt[i-1];
        //for(int i=1;i<n;++i) cout<<dp[i];
        vector<string> ans;
        for(int i=0;i<words.size();++i)
        {
            if(words[i].length() != n) continue;
            
                    unordered_map<char,int> m1;
              for(int k=0;k<words[i].length();++k) m1[words[i][k]]++;
            
            if(m[patt[0]] != m1[words[i][0]])continue;
            
            int j;
            for(j=1;j<words[i].length();++j)
                if((dp[j] != (words[i][j]!=words[i][j-1])) 
                  or m[patt[j]] != m1[words[i][j]]
                  )
                    break;
          //  cout<<j<<endl;
            if(j==words[i].length()) ans.push_back(words[i]);
        }
        return ans;
    }
};