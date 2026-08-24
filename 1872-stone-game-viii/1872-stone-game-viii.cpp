class Solution {
public:
    int n;
    vector<int> pre;
    vector<int> dp;
    // int f(int i){
    //     if(i==n-1) return pre[i];
    //     if(dp[i]!=-1) return dp[i];
    //     int take=pre[i]-f(i+1);
    //     int skip=f(i+1);
    //     return dp[i]=max(take,skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        pre.assign(n,0);
        dp.assign(n,-1);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
            pre[i]=sum;
        }
        dp[n-1]=pre[n-1];
        for(int i=n-2;i>=1;i--){
            dp[i]=max(dp[i+1],pre[i]-dp[i+1]);
        }
        return dp[1];
    }
};