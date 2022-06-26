class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int len = nums.size();

        if (len < 4)
        {
            return vector<vector<int>>();
        }

        set<vector<int>> semi_result;

        int i = 0, j = i + 1, k=j+1,l = len - 1;

        sort(nums.begin(), nums.end());

        while (i < len - 3)
        {
            j = i + 1;
            while (j < len-2)
            {
                k=j+1,l = len - 1;
                while(k < l)
                {
                 long int sum =(long)((long)nums[i] +(long) nums[j] + (long)nums[k]+(long)nums[l]);
				
                if (sum < target)
                {
                    k++;
                }
				
                else if (sum > target)
                {
                    l--;
                }

                else
                {
                    semi_result.insert(vector<int>({nums[i], nums[j],nums[k++], nums[l--]}));
                }   
              }
                j++;
            }
            i++;
        }

        return vector<vector<int>>(semi_result.begin(), semi_result.end());   
    }
};