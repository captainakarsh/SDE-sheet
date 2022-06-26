class Solution {
public:
void _merge(vector<int>& nums, int low, int mid, int high, int &ans) {
    int leftInd = low, rightInd = mid+1, r = rightInd, temp[high-low+1], tempInd = 0, counter = 0;
    // 4 6 8,  1 2 3
    while(leftInd<=mid) {
        while( r<=high && (nums[leftInd] > (long)2*nums[r]) ) {counter++; r++;}
        ans+= counter;
        while( rightInd<=high && nums[rightInd]<=nums[leftInd] ) {
            temp[tempInd++] = nums[rightInd++];
        }
        temp[tempInd++] = nums[leftInd++];
    }
    while(rightInd<=high) {
        temp[tempInd++] = nums[rightInd++];
    }
    for(int i=0; i<tempInd; i++) nums[low++] = temp[i];
}

void _mergeSort(vector<int>& nums, int l, int h, int &ans) {
    if(l < h) {
        int mid = l + (h-l)/2;
        _mergeSort(nums, l, mid, ans);
        _mergeSort(nums, mid+1, h, ans);
        _merge(nums, l, mid, h, ans);
    }
}

int reversePairs(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    if(n<=1) ans;
    _mergeSort(nums, 0, n-1, ans);
    return ans;
}
};