class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool f(int i,int j,string s,string p){
        if(i==n){
            if(j==m) return true;
            if(j+1<m && p[j+1]=='*') return f(i,j+2,s,p);
            return false;
        }
        if(j==m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(j+1<m && p[j+1]=='*'){
            ans=ans | f(i,j+2,s,p);
            if(s[i]==p[j] || p[j]=='.') ans=ans | f(i+1,j,s,p);
        }
        else if(s[i]==p[j] || p[j]=='.') ans=ans | f(i+1,j+1,s,p);
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        dp.assign(n,vector<int> (m,-1));
        return f(0,0,s,p);
    }
};