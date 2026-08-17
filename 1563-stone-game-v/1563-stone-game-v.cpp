class Solution {
public:
    #define ll long long
    int n;
    vector<vector<ll>> dp;
    vector<ll> pre;
    ll f(int i,int j,vector<int>& stoneValue){
        if(i>=j) return 0;
        // if(i<0 || j<0) return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=0;
        for(int k=i;k<=j;k++){
            ll val1=pre[k+1]-pre[i];
            ll val2=pre[j+1]-pre[k+1];
            if(val1<val2) ans=max(ans,val1+f(i,k,stoneValue));
            else if(val1>val2) ans=max(ans,val2+f(k+1,j,stoneValue));
            else{
                ans=max(ans,val1+f(i,k,stoneValue));
                ans=max(ans,val2+f(k+1,j,stoneValue));
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        ll sum=0;
        pre.assign(n+1,0);
        for(int i=0;i<n;i++){
            sum+=stoneValue[i];
            pre[i+1]=sum;
        }
        dp.assign(n+1,vector<ll>(n+1,-1));
        return (int)f(0,n-1,stoneValue);
    }
};