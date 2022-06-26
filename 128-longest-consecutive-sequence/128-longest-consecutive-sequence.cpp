class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
    unordered_map<int,int> m;
    int ans = 1;
    for ( int i: nums){
        if ( m[i] ) continue;
        
        m[i] = 1;
        
        if ( m[i-1]){
            
            int len = 1 + m[i-1];
            m[i] = len;                           
            m[i-len+1] ++;                      
            ans = max( ans, len );
        }
        
        if ( m[i+1] ){
            
            int len   = m[i + m[i+1]] + m[i];
            int start = i-m[i]+1;
            int end   = i+m[i+1];
            m[start] = len;
            m[end]   = len;
            ans = max( ans, len );
        }
    }
    return ans;
    }
};