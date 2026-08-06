class Solution {
public:
    int f(int n){
        int pdct=1;
        while(n){
            pdct*=(n%10);
            n=n/10;
        }
        return pdct;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int val=f(i);
            if(val%t==0) return i;
        }
        return -1;
    }
};