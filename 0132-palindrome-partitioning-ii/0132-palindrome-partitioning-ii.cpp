class Solution {
public:
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int f(int i,string &s){
    //     if(i==s.size()) return 0;
    //     int ans=1e9;
    //     for(int k=i;k<s.size();k++){
    //         if(check(i,k,s)){
    //             ans=min(ans,1+f(k+1,s));
    //         }
    //     }
    //     return ans;
    // }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            for(int k=i;k<n;k++){
                if(check(i,k,s)){
                    dp[i]=min(dp[i],1+dp[k+1]);
                }
            }
        }
        return dp[0]-1;
    }
};