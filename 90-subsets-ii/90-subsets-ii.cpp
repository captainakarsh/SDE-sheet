class Solution {
public:
void help(vector<int> &nums, int i,vector<int> &vec,vector<vector<int> > &res) {
		res.push_back(vec);
		for (int j = i; j != nums.size(); ++j) {
		if (j == i || nums[j] != nums[j - 1]) { 
				vec.push_back(nums[j]);
				help(nums,j+1,vec,res);
				vec.pop_back();
			}
		}
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        vector<int> t;
        help(nums,0,t,ans);
        return ans;
    }
};