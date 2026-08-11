class Solution {
public:
    vector<vector<bool>> dp;
    // bool check(int i,int j,string &s){
    //     if(i>j) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j]=check(i+1,j-1,s);
    //     }
    //     return dp[i][j]=false;
    // }
    int countSubstrings(string s) {
        int n=s.size();
        dp.assign(n+1,vector<bool>(n+1,false));
        int ans=0;
        // Blue print for this type of palindromic question
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j) dp[i][i]=true;
                else if(i+1==j) dp[i][j]=(s[i]==s[j]);
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};