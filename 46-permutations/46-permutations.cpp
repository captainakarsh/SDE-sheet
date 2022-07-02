class Solution {
public:
    void help(vector<int> nums,int index,vector<vector<int>>& ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();++i)
        {
            int temp = nums[i];
            nums[i]=nums[index];
            nums[index]=temp;
            
            help(nums,index+1,ans);
            
            temp = nums[i];
            nums[i]=nums[index];
            nums[index]=temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(nums,0,ans);
        return ans;
    }
};