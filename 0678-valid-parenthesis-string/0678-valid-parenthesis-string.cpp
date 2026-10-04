class Solution {
public:
    int dp[101][101];
    bool f(int i,int opn,string &s){
        if(opn<0) return false;
        if(i==s.size()) return opn==0;
        if(dp[i][opn]!=-1) return dp[i][opn];
        bool ans=false;
        if(s[i]=='(') ans=ans | f(i+1,opn+1,s);
        else if(s[i]==')') ans=ans | f(i+1,opn-1,s);
        else{
            ans=ans | f(i+1,opn+1,s);
            ans=ans | f(i+1,opn-1,s);
            ans=ans | f(i+1,opn,s);
        }
        return dp[i][opn]=ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,s);
    }
};