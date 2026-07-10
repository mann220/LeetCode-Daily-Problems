class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dp;
    int f(vector<pair<int,int>> &v,int val){
        int lo=0;
        int hi=v.size()-1;
        int result=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(v[mid].first<=val){
                result=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<int> NodeToIdx(n);
        for(int i=0;i<n;i++) NodeToIdx[v[i].second]=i;
        rows=n;
        cols=log2(n)+1;
        dp.resize(rows,vector<int>(cols,0));
        // fill 0th col first
        for(int node=0;node<n;node++){
            dp[node][0]=f(v,v[node].first+maxDiff);
        }
        // fill remainig col
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                dp[node][j]=dp[dp[node][j-1]][j-1];
            }
        }
        vector<int> result;
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            int a=NodeToIdx[u];
            int b=NodeToIdx[v];
            if(a==b){
                result.push_back(0);
                continue;
            }
            if(a>b) swap(a,b);
            int curr=a;
            int jumps=0;
            for(int j=cols-1;j>=0;j--){
                if(dp[curr][j]<b){
                    curr=dp[curr][j];
                    jumps+=(1<<j); // 2^j
                }
            }
            if(dp[curr][0]>=b) result.push_back(jumps+1);
            else result.push_back(-1);
        }
        return result;
    }
};