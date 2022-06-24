class Solution {
public:
    bool isPossible(vector<int>& target) {
     long long int sum=0;
        priority_queue<int> p;
        for(int i=0;i<target.size();++i)
        {
            sum+=target[i];
            p.push(target[i]);
        }
          while(p.top() != 1){
            sum -= p.top();
            if(sum == 0 || sum >= p.top()) return false;
            int old = p.top()%sum;
            if(sum != 1 && old == 0) return false;
            p.pop();
            p.push(old);
            sum += (old);
        }
        return true;
    }
};