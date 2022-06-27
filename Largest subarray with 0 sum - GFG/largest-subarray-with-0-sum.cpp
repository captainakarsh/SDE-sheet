// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        m[A[0]]=1;
        for(int i=1;i<n;++i)
        {
            A[i]+=A[i-1];
            if(!m[A[i]])
            m[A[i]]=i+1;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;++i)
        {
            if(A[i] == 0)
            {
                ans=max(ans,i+1);
            }
            else
            {
                if(m[A[i]] and m[A[i]] <= i)
                {
                    ans=max(ans,((i+1)-m[A[i]]));
                }
            }
        }
        if(ans==INT_MIN)
        return 0;
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends