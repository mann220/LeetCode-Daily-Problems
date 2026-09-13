class Solution {
public:
    vector<int> dp;
    bool f(int i,string &s,unordered_map<string,int> &mpp){
        int n=s.size();
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i]==1;
        bool ans=false;
        for(int k=i;k<n;k++){
            string p=s.substr(i,k-i+1);
            if(mpp.find(p)!=mpp.end()) ans=ans | f(k+1,s,mpp);
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& v) {
        int n=v.size();
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++) mpp[v[i]]++;
        dp=vector<int> (s.size()+1,-1);
        return f(0,s,mpp);
    }
};