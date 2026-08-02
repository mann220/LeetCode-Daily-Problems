class Solution {
public:
    #define ll long long
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<ll> dif(n+1,0);
        // this is the best way to solve these type of qeu\\uery
        for(auto it:boosts){
            int l=it[0];
            int r=it[1];
            int v=it[2];
            dif[l]+=v;
            dif[r+1]-=v;
        }
        vector<ll> bonus(n,0);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=dif[i];
            bonus[i]=sum;
        }
        ll req=0;
        for(int i=n-1;i>=0;i--){
            if(req>0) req+=monsters[i];
            else req=max(0LL,(ll)monsters[i]-bonus[i]);
        } 
        return req;
    }
};