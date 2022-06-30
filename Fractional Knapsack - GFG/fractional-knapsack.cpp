// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
       vector<pair<float,pair<int,int>>>v;
       for(int i=0;i<n;i++)
       {
           float d=float(arr[i].value)/float(arr[i].weight);
           pair<int,int>p={arr[i].value,arr[i].weight};
           v.push_back(make_pair(d,p));
       }
       sort(v.begin(),v.end());
       double value=0;
       for(int i=n-1;i>=0;i--)
       {
           if(v[i].second.second>W)
           {
               value=value+v[i].first*(W);
               break;
           }
           value=value+v[i].second.first;
           W=W-v[i].second.second;
       }
       return value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends