class Solution {
public:
    int bs(vector<int>& v, int l,int h,int &target)
    {
        while(l<=h)
        {
            int m = (l+h)>>1;
            if(v[m] == target)
                return m;
            if(target > v[m])
                l = m+1;
            else h=m-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r= n-1;
        while(l<r)
        {
            int m = (l+r)>>1;
            if(nums[m]>nums[r])
                l=m+1;
            else
                r=m;
        }
       int pivot = l;
        int x = bs(nums,0,pivot-1,target);
        int y = bs(nums,pivot,n-1,target);
        if(x==-1 and y==-1) return -1;
        if(x==-1) return y;
        return x;
    }
};