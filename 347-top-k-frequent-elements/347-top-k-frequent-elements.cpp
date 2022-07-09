class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;   
        
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        for(auto i:m){
            if(pq.size()<k)
            {
                pq.push(make_pair(i.second,i.first));
            }
            else
            {
                if(pq.top().first < i.second)
                {
                    pq.pop();
                    pq.push(make_pair(i.second,i.first)); 
                }
            }
            
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};