class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
          int lm=height[0],rm=height[n-1],l=1,r=n-2,ans=0;
          bool flag;
          while(l<=r){
            flag = lm<rm? true:false;
            if(flag){
                if(height[l]>lm)
                  lm=height[l];
                else
                  ans+=lm-height[l];
                l++;
            }else{
              if(height[r]>rm)
                rm=height[r];
              else
                ans+=rm-height[r];
              r--;
             }
      }
      return ans;
    }
};