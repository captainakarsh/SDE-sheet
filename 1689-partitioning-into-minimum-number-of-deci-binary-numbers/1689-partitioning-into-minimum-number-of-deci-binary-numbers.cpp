class Solution {
public:
    int minPartitions(string n) {
        int m=INT_MIN,t;
        for(auto i:n)
        {
            t=i-'0';
            if(t >m)
                m=t;
        }
        return m;
    }
};