class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        for(int k=0;k<=j;)
        {
            
            if(nums[k]==0)
            {
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                i++;k++;
            }
            else if(nums[k]==2)
            {
                int temp=nums[j];
                nums[j]=nums[k];
                nums[k]=temp; 
                j--;
            }
            else
                k++;
        }
        

    }
};