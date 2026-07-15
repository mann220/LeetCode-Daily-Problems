class Solution {
public:
    #define ll long long
    int gcdOfOddEvenSums(int n) {
        ll sumodd=0;
        ll sumeve=0;
        int p=n;
        int n1=1;
        int n2=2;
        while(p--){
            sumodd+=n1;
            n1+=2;
            sumeve+=n2;
            n2+=2;
        }
        return __gcd(sumodd,sumeve);
    }
};