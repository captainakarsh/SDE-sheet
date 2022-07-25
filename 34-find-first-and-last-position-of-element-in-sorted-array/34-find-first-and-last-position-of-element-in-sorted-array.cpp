class Solution {
public:
    int li(vector<int>& nums,int i,int j,int target){
        if(i<=j){
            int m = (i+j)>>1;
            if(nums[m] == target){
                if(m==0 or nums[m-1]!=target){
                    return m;
                }else{
                    return li(nums,i,m-1,target);
                }
            }
            if(target < nums[m]){
               return li(nums,i,m-1,target);
            }
            return li(nums,m+1,j,target);
        }
        return -1;
    }
    int ui(vector<int>& nums,int i,int j,int target){
        if(i<=j){
            int m = (i+j)>>1;
            if(nums[m] == target){
                if(m==nums.size()-1 or nums[m+1]!=target){
                    return m;
                }else{
                    return ui(nums,m+1,j,target);
                }
            }
            if(target < nums[m]){
               return ui(nums,i,m-1,target);
            }
            return ui(nums,m+1,j,target);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(li(nums,0,nums.size()-1,target));
        ans.push_back(ui(nums,0,nums.size()-1,target));
        return ans;
    }
};