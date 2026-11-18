class Solution {
public:
    vector<int> dp;
    int lb(int val,vector<pair<pair<int,int>,int>> &v){
        int lo=0;
        int hi=v.size()-1;
        int ans=v.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid].first.first>=val){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
    int f(int i,vector<pair<pair<int,int>,int>> &v){
        if(i==v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int ind=lb(v[i].first.second,v);
        ans=max(ans,v[i].second+f(ind,v));
        ans=max(ans,f(i+1,v));
        return dp[i]=ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++) v.push_back({{startTime[i],endTime[i]},profit[i]});
        sort(v.begin(),v.end());
        dp=vector<int> (n,-1);
        return f(0,v);
    }
};