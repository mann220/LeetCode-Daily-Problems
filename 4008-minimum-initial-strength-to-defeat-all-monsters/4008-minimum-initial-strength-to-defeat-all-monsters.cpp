class Solution {
public:
    #define ll long long
    bool f(ll mid,vector<int>& m,vector<ll> &b){
        int n=m.size();
        for(int i=0;i<n;i++){
            if(mid+b[i]<m[i]) return false;
            mid-=m[i];
            if(mid<0) mid=0;
        }
        return true;
    }
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
        ll lo=0;
        ll hi=accumulate(monsters.begin(),monsters.end(),0LL);
        ll ans;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(f(mid,monsters,bonus)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }        
        return ans;
    }
};