class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int len = nums.size();

        if (len < 3)
        {
            return vector<vector<int>>();
        }

        set<vector<int>> semi_result;

        int i = 0, j = i + 1, k = len - 1;

        sort(nums.begin(), nums.end());

        while (i < len - 2)
        {
            j = i + 1, k = len - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
				
                if (sum < 0)
                {
                    j++;
                }
				
                else if (sum > 0)
                {
                    k--;
                }

                else
                {
                    semi_result.insert(vector<int>({nums[i], nums[j++], nums[k--]}));
                }
            }
            i++;
        }

        return vector<vector<int>>(semi_result.begin(), semi_result.end());   
    }
};