class Solution {
public:
    map<pair<int,int>,int> mpp;
    int f(int i,int maxi,vector<pair<int,int>> &v){
        int n=v.size();
        if(i>=n){
            if(maxi>=n-1) return 0;         // garden last point is n not n+1 becaus range.size()==n+1;
            return 1e9;
        }
        if(maxi<v[i].first) return 1e9;
        if(mpp.count({i,maxi})) return mpp[{i,maxi}];
        int ans=1e9;
        ans=min(ans,f(i+1,maxi,v));
        ans=min(ans,1+f(i+1,max(maxi,v[i].second),v));
        return mpp[{i,maxi}]=ans;
    }
    int minTaps(int n, vector<int>& ranges) {
        // mpp.clear();
        vector<pair<int,int>> v;
        for(int i=0;i<=n;i++) v.push_back({max(i-ranges[i],0),min(i+ranges[i],n)});
        sort(v.begin(),v.end());
        int val=f(0,0,v);
        if(val==1e9) return -1;
        return val;
    }
};