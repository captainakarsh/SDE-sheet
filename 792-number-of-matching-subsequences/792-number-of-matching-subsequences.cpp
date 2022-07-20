class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
             int ans=0;
        unordered_map<char,vector<int>>m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        for(string i:words){
            int last_idx=s.size();
            bool flag=true;
            for(int j=i.size()-1;j>=0;j--){
                bool match=false;
                
                for(int k=m[i[j]].size()-1;k>=0;k--){
                    
                   if(last_idx>m[i[j]][k]){
                       match=true;
                       last_idx=m[i[j]][k];
                       break;
                    }
                }
                if(!match){
                    flag=false;
                    break;
                }
            }
            if(flag)  ans++;
        
        }
        return ans;
    }
};