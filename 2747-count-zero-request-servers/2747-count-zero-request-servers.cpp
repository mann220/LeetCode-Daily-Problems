class Solution {
public:
    // my first approach of bs is wrong because the id can be on different time so it will not give correct answer so we have to think of different solutios.
    // second observation which i got from seeing hint is that can we use two pointer by sorting both array on the basis of time

    // int lb(vector<vector<int>> &logs,int target){
    //     int lo=0;
    //     int hi=logs.size()-1;
    //     int ans=logs.size();
    //     while(lo<=hi){
    //         int mid=lo+(hi-lo)/2;
    //         if(logs[mid][1]<=target){
    //             ans=mid;
    //             lo=mid+1;
    //         }
    //         else hi=mid-1;
    //     }
    //     return ans;
    // }
    // int ub(vector<vector<int>> &logs,int target){
    //     int lo=0;
    //     int hi=logs.size()-1;
    //     int ans=hi+1;
    //     while(lo<=hi){
    //         int mid=lo+(hi-lo)/2;
    //         if(logs[mid][1]>target){
    //             ans=mid;
    //             hi=mid-1;
    //         }
    //         else lo=mid+1;
    //     }
    //     return ans;
    // }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>> v;
        for(int i=0;i<logs.size();i++) v.push_back({logs[i][1],logs[i][0]});
        sort(v.begin(),v.end());
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++) q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        vector<int> ans(q.size(),0);
        unordered_map<int,int> mpp;
        int val=0;
        int lft=0;
        int rgt=0;
        for(int i=0;i<q.size();i++){
            int l=q[i].first-x;
            int r=q[i].first;
            while(rgt<v.size() && v[rgt].first<=r){
                int id=v[rgt].second;
                mpp[id]++;
                if(mpp[id]==1) val++;
                rgt++;
            }
            while(lft<rgt && v[lft].first<l){
                int id=v[lft].second;
                mpp[id]--;
                if(mpp[id]==0) val--;
                lft++;
            }
            ans[q[i].second]=n-val;
        }
        return ans;
    }
};