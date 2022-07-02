class Solution {
public:
    void next(vector<int> &n)
    {
        int index=-1;
        for(int i=n.size()-1;i>0;--i)
        {
            if(n[i-1]<n[i]){
                index = i-1;
                break;
            }
        }
        if(index==-1)return;
        for(int i=n.size()-1;i>index;--i)
        {
            if(n[i]>n[index])
            {
                int temp = n[index];
                n[index] = n[i];
                n[i] = temp;
                break;
            }
        }
        int i = index+1,j = n.size()-1;
        while(i<j)
        {
            int temp = n[i];
            n[i] = n[j];
            n[j] = temp;
            i++;j--;
        }
    }
    string getPermutation(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=n;++i)
        ans.push_back(i);k--;
        while(k)
        {
            next(ans);
            k--;
        }
        string fans="";
        for(int i=0;i<n;++i)
        {
            fans=fans+ to_string(ans[i]);
        }
        return fans;
    }
};