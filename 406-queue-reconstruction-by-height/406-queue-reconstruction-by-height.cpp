class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
         sort(people.begin(),people.end());
        for(int i=0;i<n;++i)
        {
            int k = people[i][1]+1,j=0;
            while(k and j<n)
            {
                if(ans[j][0] == -1 or ans[j][0]>=people[i][0])
                    k--;
                j++;
            }
            ans[j-1][0] = people[i][0];
            ans[j-1][1] = people[i][1];
           // for(auto i:ans)
           // cout<<i[0]<<" "<<i[1]<<endl;
            //cout<<endl<<endl;
        }
        return ans;
    }
};