class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int n1 = num1.length()-1,n2 = num2.length()-1;
        int c = 0;
        while(n1>=0 and n2>=0)
       {
            int a = num1[n1]-'0';
            int b = num2[n2]-'0';
            a = a+b+c;
        int t = a%10;
             c = a/10;
            
            ans=to_string(t)+ans;
             n1--;n2--;
        }
        while(n1>=0)
        {
            int a = num1[n1]-'0';
            a=a+c;
           int t = a%10;
             c = a/10;
            ans=to_string(t)+ans;
            n1--;
        }
        while(n2>=0)
        {
            int a = num2[n2]-'0';
            a=a+c;
           int t = a%10;
             c = a/10;
            ans=to_string(t)+ans;
            n2--;
        }
        if(c>0)
        {
            ans=to_string(c)+ans;
        }
        return ans;
    }
};