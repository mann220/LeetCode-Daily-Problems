class Solution {
public:
    // int f(int i,int j,string &s,string &t,vector<vector<int>>& dp){
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=0;
    //     if(s[i]==t[j]) ans+=f(i+1,j+1,s,t,dp);
    //     ans+=f(i+1,j,s,t,dp);
    //     return dp[i][j]=ans;
    // }
    #define ll long long
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<unsigned ll> prev(m+1,0);
        prev[m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]) prev[j]+=prev[j+1];
            }
        }
        return prev[0];
    }
};