class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1) return nums[0];
        
        int l=0, r=nums.size()-1;
        
        while(l < r){
           int mid = (l+r)>>1;
           int t = (mid%2 == 0) ? mid+1 : mid-1;
            if(nums[mid]==nums[t]) l = mid+1;
            else r = mid;
        }
        return nums[l];
    }
};