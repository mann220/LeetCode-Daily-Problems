class Solution {
public:
    // observation if there is a perfect square then alice wins the game 
    vector<bool> dp;
    // bool f(int n){
    //     if(n==0) return false;
    //     if(dp[n]!=-1) return dp[n];
    //     for(int j=1;j*j<=n;j++){
    //         if(!f(n-j*j)) return true;
    //     }
    //     return dp[n]=false;
    // }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,false);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(!dp[i-j*j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};