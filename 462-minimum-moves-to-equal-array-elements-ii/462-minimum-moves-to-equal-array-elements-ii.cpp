class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = n>>1;
        int ans = 0;
        for(int i=0;i<n;++i)
            ans=ans+(abs(nums[m]-nums[i]));
        return ans;
    }
};