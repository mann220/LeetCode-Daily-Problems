class Solution {
public:
    // ( -> -1 
    // * -> 0 
    // ) -> 1
    int dp[101][101][101];
    bool f(int i,int cnt1,int cnt2,string &s){
        if(cnt1<cnt2) return false;
        if(i==s.size()){
            if(cnt1==cnt2) return true;
            return false;
        }
        if(dp[i][cnt1][cnt2]!=-1) return dp[i][cnt1][cnt2]==1;
        bool ans=false;
        if(s[i]=='(') ans=ans | f(i+1,cnt1+1,cnt2,s);
        else if(s[i]==')') ans=ans | f(i+1,cnt1,cnt2+1,s);
        else{
            ans=ans | f(i+1,cnt1,cnt2,s);
            ans=ans | f(i+1,cnt1+1,cnt2,s);
            ans=ans | f(i+1,cnt1,cnt2+1,s);
        }
        return dp[i][cnt1][cnt2]=ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s);
    }
};