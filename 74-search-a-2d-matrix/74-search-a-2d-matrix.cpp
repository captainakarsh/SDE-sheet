class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix.size()*matrix[0].size()-1;
        while(i<=j)
        {
            int m=(i+j)>>1;
            int r=m/matrix[0].size();
            int c=m%matrix[0].size();
            if(matrix[r][c]==target)
                return true;
            
            if(target > matrix[r][c])
            {
                i=m+1;
                
            }
            else
            {
                j=m-1;
            }
            
        }
        return false;
    }
};