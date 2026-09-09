class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n>=1e3) ans+=n-1e3+1;
        if(n>=1e6) ans+=n-1e6+1;
        if(n>=1e9) ans+=n-1e9+1;
        if(n>=1e12) ans+=n-1e12+1;
        if(n>=1e15) ans+=n-1e15+1;
        return ans;
    }
};