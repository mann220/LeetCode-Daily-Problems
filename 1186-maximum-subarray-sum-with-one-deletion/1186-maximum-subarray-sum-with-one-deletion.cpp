class Solution {
public:
    static const int val=1e5+1;
    int dp[val][2][2][2];
    int f(int i,int flg,int strt,int end,vector<int>& arr){
        int n=arr.size();
        if(i==n) return 0;
        if(end==1) return 0;
        if(dp[i][flg][strt][end]!=-1) return dp[i][flg][strt][end];
        int ans=-1e9;
        // first option we can take it 
        if(strt==0){
            ans=max(ans,f(i+1,flg,0,0,arr));
            ans=max(ans,f(i+1,0,1,0,arr));
            ans=max(ans,f(i+1,0,1,1,arr));
            ans=max(ans,arr[i]+f(i+1,1,1,0,arr));
            ans=max(ans,arr[i]+f(i+1,1,1,1,arr));
        }
        else{
            if(flg){
                ans=max(ans,f(i+1,0,1,0,arr));
                ans=max(ans,f(i+1,0,1,1,arr));
            }
            ans=max(ans,arr[i]+f(i+1,flg,strt,0,arr));
            ans=max(ans,arr[i]+f(i+1,flg,strt,1,arr));
        }
        return dp[i][flg][strt][end]=ans;
    }
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,0,0,arr);
        if(ans==0) return *max_element(arr.begin(),arr.end());
        return ans;
    }
};