class Solution {
public:
    unordered_map<int,int> mpp;
    int f(int n){
        if(n==0 || n==1) return n;
        if(mpp.count(n)) return mpp[n]; 
        // we have two options
        return mpp[n]=1+min(n%2+f(n/2),n%3+f(n/3));
    }
    int minDays(int n) {
        return f(n);
    }
};