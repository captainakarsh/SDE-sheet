// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int v) 
	{ 
	    // Your code goes here
	    int dp[n+1][v+1];
	    for(int i=0;i<=n;++i)
	    dp[i][0]=0;
	    for(int i=1;i<=v;++i)
	    dp[0][i]=INT_MAX-1;
	    
	    for(int i=1;i<=n;++i)
	    {
	        for(int j=1;j<=v;++j)
	        {
	            if(j < coins[i-1])
	            dp[i][j]=dp[i-1][j];
	            else
	             dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-coins[i-1]]);
	        }
	    }
	    if(dp[n][v] == INT_MAX-1) return -1;
	    return dp[n][v];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends