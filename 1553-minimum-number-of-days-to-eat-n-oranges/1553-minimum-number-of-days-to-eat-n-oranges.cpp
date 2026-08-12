class Solution {
public:
    int f(int n){
        if(n==0 || n==1) return n;
        // we have two options
        return 1+min(n%2+f(n/2),n%3+f(n/3));
    }
    int minDays(int n) {
        return f(n);
    }
};