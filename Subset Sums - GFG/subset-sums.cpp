// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void help(vector<int> &arr ,int i, int sum,int &n,vector<int> &ans)
    {
        if(i==n)
        {
            
            ans.push_back(sum);
            return;
        }
        help(arr,i+1,sum,n,ans);
        help(arr,i+1,sum+arr[i],n,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        help(arr,0,0,n,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends