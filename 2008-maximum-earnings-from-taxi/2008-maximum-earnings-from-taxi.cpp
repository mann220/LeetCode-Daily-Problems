class Solution {
public:
    // i think here the logic is binary search and dp or finding index we have to do bs
    #define ll long long
    vector<ll> dp;
    ll f(int i,vector<pair<int,pair<int,int>>> &v){
        int n=v.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll ans=0;
        int lb=lower_bound(v.begin(),v.end(),v[i].second.first,[](const pair<int,pair<int,int>> &a,int val){
            return a.first<val;
        })-v.begin();
        ll take=v[i].second.second+f(lb,v);
        ll nottake=f(i+1,v);
        ans=max(take,nottake);
        return dp[i]=ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<pair<int,pair<int,int>>> v;
        dp=vector<ll> (rides.size()+1,-1);
        for(int i=0;i<rides.size();i++){
            v.push_back({rides[i][0],{rides[i][1],rides[i][1]-rides[i][0]+rides[i][2]}});
        }
        sort(v.begin(),v.end());
        return f(0,v);
    }
};