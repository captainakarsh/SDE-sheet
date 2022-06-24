class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<nums1.size();++i,++j)
            nums1[i]=nums2[j];
        int g=m+n;
        while(g>=2)
        {
            int gap = (g+1)>>1;
            int i=0,j=gap;
            while(j<(m+n))
            {
                if(nums1[i]>nums1[j])
                {
                    int temp=nums1[i];
                    nums1[i]=nums1[j];
                    nums1[j]=temp;
                }
                i++;j++;
            }
            g=gap;
        }
    }
};