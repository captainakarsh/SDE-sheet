class Solution {
public:
    int fib(int n) {
        if(!n or n==1) return n;
        return fib(n-1) + fib(n-2);
    }
};