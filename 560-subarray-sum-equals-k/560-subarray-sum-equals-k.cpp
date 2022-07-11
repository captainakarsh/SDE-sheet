class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> m;
        int sum=0,ans=0;
        m[sum] = 1;
        for(auto it:nums){
            sum += it;
            int t = sum - k;
            if(m.find(t) != m.end()){
                ans += m[t];
            }
            m[sum]++;
        }
        return ans;
    }
};