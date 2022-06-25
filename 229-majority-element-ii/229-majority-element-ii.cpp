class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;++i)
            m[nums[i]]++;
        n=n/3;
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second > n)
             ans.push_back(i.first);
        }
        return ans;
    }
};