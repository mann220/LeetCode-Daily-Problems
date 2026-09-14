class Solution {
public:
    // ( -> -1 
    // * -> 0 
    // ) -> 1
    // int dp[101][101][101];
    // bool f(int i,int cnt1,int cnt2,string &s){
    //     if(cnt1<cnt2) return false;
    //     if(i==s.size()){
    //         if(cnt1==cnt2) return true;
    //         return false;
    //     }
    //     if(dp[i][cnt1][cnt2]!=-1) return dp[i][cnt1][cnt2]==1;
    //     bool ans=false;
    //     if(s[i]=='(') ans=ans | f(i+1,cnt1+1,cnt2,s);
    //     else if(s[i]==')') ans=ans | f(i+1,cnt1,cnt2+1,s);
    //     else{
    //         ans=ans | f(i+1,cnt1,cnt2,s);
    //         ans=ans | f(i+1,cnt1+1,cnt2,s);
    //         ans=ans | f(i+1,cnt1,cnt2+1,s);
    //     }
    //     return dp[i][cnt1][cnt2]=ans;
    // }
    bool checkValidString(string s) {
        // memset(dp,-1,sizeof(dp));
        int n=s.size();
        vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>> (n+1,vector<bool> (n+1,false)));
        for(int i=0;i<=n;i++) dp[n][i][i]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j<k) continue;
                    bool ans=false;
                    if(s[i]=='(') ans=ans | dp[i+1][j+1][k];
                    else if(s[i]==')') ans=ans | dp[i+1][j][k+1];
                    else{
                        ans=ans | dp[i+1][j][k];
                        ans=ans | dp[i+1][j+1][k];
                        ans=ans | dp[i+1][j][k+1];
                    }
                    dp[i][j][k]=ans;
                }
            }
        }
        return dp[0][0][0];
    }
};