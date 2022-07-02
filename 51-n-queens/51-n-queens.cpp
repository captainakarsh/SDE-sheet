class Solution {
public:
    bool isValid(int n,int row,int col, vector<vector<bool>>& ans)
    {
      int i, j;

    for (i = 0; i < row; i++)
        if (ans[i][col])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (ans[i][j])
            return false;

    for (i = row, j = col; j <n && i >=0; i--, j++)
        if (ans[i][j])
            return false;
 
    return true;
    }
    
    void help(int n,int i, vector<vector<bool>>& ans,vector<vector<string>>& fans)
    {
        if(i==n)
        {
            vector<string> v;
            for(int j=0;j<n;++j)
            {
                string s="";
                for(int l=0;l<n;++l)
                {
                    if(ans[j][l])
                    {
                        s+='Q';
                    }
                    else
                    {
                        s+='.';
                    }
                }
                v.push_back(s);
            }
            fans.push_back(v);
            return;
        }
        for(int k=0;k<n;++k)
        {
            if(isValid(n,i,k,ans))
            {
                ans[i][k]=true;
                help(n,i+1,ans,fans);
                ans[i][k]=false;
            }
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> fans;
        vector<vector<bool>> ans(n);
        for(int i=0;i<n;++i)
        {
            vector<bool> v(n,false);
            ans[i]=v;
        }
        help(n,0,ans,fans);
        return fans;
    }
};