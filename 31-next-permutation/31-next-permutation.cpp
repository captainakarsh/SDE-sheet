class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int l = arr.size(),index=-1;
        for(int i=l-2;i>=0;--i)
        {
            if(arr[i]<arr[i+1])
            {
                index=i;
                break;
            }
        }
        for(int i=l-1;i>index and index!=-1;--i)
        {
            if(arr[i]>arr[index]){
                int temp = arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
                break;
            }
        }
        int lo=index+1,h=l-1;
        while(lo<=h){
            int temp = arr[lo];
            arr[lo]=arr[h];
            arr[h]=temp;
            lo++;
            h--;
        }
    }
};