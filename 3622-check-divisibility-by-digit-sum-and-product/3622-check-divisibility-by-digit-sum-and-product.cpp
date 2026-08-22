class Solution {
public:
    int f(int n){
        int sum=0;
        int pdct=1;
        while(n){
            int lst=n%10;
            sum+=lst;
            pdct=pdct*lst;
            n=n/10;
        }
        return (sum+pdct);
    }
    bool checkDivisibility(int n) {
        int val=f(n);
        return n%val==0;
    }
};