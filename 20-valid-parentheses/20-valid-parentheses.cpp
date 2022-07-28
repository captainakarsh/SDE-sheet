class Solution {
public:
    bool isValid(string s) {
           stack<char> mystack;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            mystack.push(s[i]);
            else
            {
              if((s[i]==']' || s[i]=='}' || s[i]==')') && (mystack.empty()))
            return false;
                if(s[i]==')' && mystack.top() != '(')
                    return false;
                if(s[i]=='}' && mystack.top() != '{')
                    return false;
                if(s[i]==']' && mystack.top() != '[')
                    return false;
                if(s[i]==')' && mystack.top() == '(')
                    mystack.pop();
                else if(s[i]=='}' && mystack.top() == '{')
                    mystack.pop();
                else if(s[i]==']' && mystack.top() == '[')
                    mystack.pop();
            }
        }
        if(mystack.empty())
            return true;
        return false;
    }
};