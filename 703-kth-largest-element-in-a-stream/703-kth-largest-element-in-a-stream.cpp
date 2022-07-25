class KthLargest {
public:
    int k;
     priority_queue<int, vector<int>, greater<int> >  q;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();++i)
        {
            if(i<k)
                q.push(nums[i]);
            else
            {
                if(nums[i]>q.top())
                {
                     q.pop();
                    q.push(nums[i]);
                }
                
            }
        }
    }
    
    int add(int val) {
        if(q.size()<k)
        {
            q.push(val);
            return q.top();
        }
        if(val>q.top())
        {
            q.pop();
            q.push(val);
            return q.top();
        }
        return q.top();    
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */