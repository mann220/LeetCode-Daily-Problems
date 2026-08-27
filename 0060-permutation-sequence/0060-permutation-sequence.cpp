class Solution {
public:
    int fact(int n){
        if(n==0 || n==1) return 1;
        return n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        int val=0;
        string ans="";
        int mask=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                if(!(mask & (1<<j))){
                    if(fact(i)>=k){
                        ans+=to_string(j);
                        mask=mask | (1<<j);
                        break;
                    }
                    else k-=fact(i);
                }
            }
        }
        return ans;
    }
};