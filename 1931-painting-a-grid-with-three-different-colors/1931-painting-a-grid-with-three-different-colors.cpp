class Solution {
public:
    int mod=1e9+7;
    int m;
    vector<vector<int>> dp;
    vector<string> states;
    void f1(int i,string s){
        if(i==m){
            states.push_back(s);
            return;
        }
        for(char ch:{'R','G','B'}){
            if(s.empty() || s.back()!=ch) f1(i+1,s+ch);
        }
        return;
    }
    int f2(int rem,int prev){
        if(rem==0) return 1;
        if(dp[rem][prev]!=-1) return dp[rem][prev];
        int ways=0;
        string prevState=states[prev];
        for(int i=0;i<states.size();i++){
            if(i==prev) continue;
            bool valid=true;
            string currState=states[i];
            for(int j=0;j<m;j++){
                if(currState[j]==prevState[j]){
                    valid=false;
                    break;
                }
            } 
            if(valid) ways=(ways+f2(rem-1,i))%mod; 
        }
        return dp[rem][prev]=ways;
    }
    int colorTheGrid(int m, int n) {
        this->m=m;
        f1(0,"");
        dp.assign(n,vector<int> (states.size()+1,-1));
        int result=0;
        for(int i=0;i<states.size();i++) result=(result+f2(n-1,i))%mod;
        return result;
    }
};